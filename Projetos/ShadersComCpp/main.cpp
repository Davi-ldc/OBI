#include <SDL.h>
#include <glad/glad.h>
#include <efsw/efsw.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <chrono>
#include <thread>
#include <atomic>
#include <mutex>
#include <queue>

#ifdef _WIN32
#include <windows.h>
#endif

// Cache de estado OpenGL para evitar chamadas redundantes
struct GLStateCache {
    GLuint currentProgram = 0;
    GLuint currentVAO = 0;
    bool dirty = true;
    
    void useProgram(GLuint program) {
        if (currentProgram != program || dirty) {
            glUseProgram(program);
            currentProgram = program;
        }
    }
    
    void bindVertexArray(GLuint vao) {
        if (currentVAO != vao || dirty) {
            glBindVertexArray(vao);
            currentVAO = vao;
        }
    }
    
    void markClean() { dirty = false; }
    void markDirty() { dirty = true; }
};

// Sistema de dirty flags para uniforms
struct UniformManager {
    GLint timeLocation = -1;
    GLint resolutionLocation = -1;
    
    float lastTime = -1.0f;
    float lastResolutionX = -1.0f;
    float lastResolutionY = -1.0f;
    
    bool timeDirty = true;
    bool resolutionDirty = true;
    
    void updateLocations(GLuint program) {
        timeLocation = glGetUniformLocation(program, "time");
        resolutionLocation = glGetUniformLocation(program, "resolution");
        markAllDirty();
    }
    
    void updateTime(float time) {
        if (timeLocation != -1 && (timeDirty || lastTime != time)) {
            glUniform1f(timeLocation, time);
            lastTime = time;
            timeDirty = false;
        }
    }
    
    void updateResolution(float width, float height) {
        if (resolutionLocation != -1 && (resolutionDirty || 
            lastResolutionX != width || lastResolutionY != height)) {
            glUniform2f(resolutionLocation, width, height);
            lastResolutionX = width;
            lastResolutionY = height;
            resolutionDirty = false;
        }
    }
    
    void markAllDirty() {
        timeDirty = true;
        resolutionDirty = true;
    }
};

// Sistema assíncrono de hot reload
class ShaderReloader : public efsw::FileWatchListener {
private:
    std::atomic<bool> needsReload{false};
    std::mutex shaderMutex;
    std::queue<std::string> changedFiles;
    
public:
    void handleFileAction(efsw::WatchID watchid, const std::string& dir,
                         const std::string& filename, efsw::Action action,
                         std::string oldFilename) override {
        
        if (action == efsw::Actions::Modified || action == efsw::Actions::Moved) {
            // Verifica se é arquivo shader
            if ((filename.length() >= 5 && filename.substr(filename.length() - 5) == ".glsl") ||
                (filename.length() >= 5 && filename.substr(filename.length() - 5) == ".vert") ||
                (filename.length() >= 5 && filename.substr(filename.length() - 5) == ".frag")) {
                std::lock_guard<std::mutex> lock(shaderMutex);
                changedFiles.push(filename);
                needsReload = true;
                std::cout << "Shader file changed: " << filename << std::endl;
            }
        }
    }
    
    bool shouldReload() {
        return needsReload.load();
    }
    
    void markReloaded() {
        std::lock_guard<std::mutex> lock(shaderMutex);
        needsReload = false;
        // Limpa a queue
        while (!changedFiles.empty()) {
            changedFiles.pop();
        }
    }
};

std::string loadShaderSource(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open shader file: " << filename << std::endl;
        return "";
    }
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

GLuint compileShader(GLenum type, const char* source) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    GLint success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char log[512];
        glGetShaderInfoLog(shader, 512, nullptr, log);
        std::cerr << "Shader compile error:\n" << log << std::endl;
    }
    return shader;
}

GLuint createProgram(const char* vertexSrc, const char* fragmentSrc) {
    GLuint vs = compileShader(GL_VERTEX_SHADER, vertexSrc);
    GLuint fs = compileShader(GL_FRAGMENT_SHADER, fragmentSrc);
    GLuint program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    
    GLint success = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char log[512];
        glGetProgramInfoLog(program, 512, nullptr, log);
        std::cerr << "Program link error:\n" << log << std::endl;
    }
    
    glDeleteShader(vs);
    glDeleteShader(fs);
    return program;
}

// Timer de alta precisão multiplataforma
class HighResTimer {
private:
#ifdef _WIN32
    LARGE_INTEGER frequency;
    LARGE_INTEGER startTime;
#else
    std::chrono::high_resolution_clock::time_point startTime;
#endif
    
public:
    HighResTimer() {
#ifdef _WIN32
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&startTime);
#else
        startTime = std::chrono::high_resolution_clock::now();
#endif
    }
    
    float getElapsedTime() {
#ifdef _WIN32
        LARGE_INTEGER currentTime;
        QueryPerformanceCounter(&currentTime);
        return static_cast<float>(currentTime.QuadPart - startTime.QuadPart) / frequency.QuadPart;
#else
        auto currentTime = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<float>(currentTime - startTime).count();
#endif
    }
};

int SDL_main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    // Configurações OpenGL otimizadas
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);
    
    SDL_Window* window = SDL_CreateWindow("GLSL + SDL2", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    
    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (!context) {
        std::cerr << "SDL_GL_CreateContext Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return 1;
    }

    // V-Sync adaptativo
    if (SDL_GL_SetSwapInterval(-1) != 0) {
        SDL_GL_SetSwapInterval(0);
    }

    // Inicializa sistemas otimizados
    GLStateCache glState;
    UniformManager uniforms;
    HighResTimer timer;
    
    // Sistema de file watching
    efsw::FileWatcher fileWatcher;
    ShaderReloader reloader;
    efsw::WatchID watchID = fileWatcher.addWatch(".", &reloader, true);
    fileWatcher.watch();
    
    // Carrega shaders iniciais
    std::string vertSrc = loadShaderSource("vertex.vert");
    std::string fragSrc = loadShaderSource("fragment.frag");
    GLuint shader = createProgram(vertSrc.c_str(), fragSrc.c_str());
    
    if (shader != 0) {
        uniforms.updateLocations(shader);
    }

    // Setup de geometria (otimizado - criado uma vez)
    float vertices[] = {
        -1.0f, -1.0f,  1.0f, -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,  1.0f, -1.0f,  1.0f
    };

    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    bool running = true;
    bool isFullscreen = false;
    SDL_Event event;
    
    int windowWidth = 800, windowHeight = 600;
    bool viewportNeedsUpdate = false;

    // Otimizações OpenGL
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glDisable(GL_BLEND);

    std::cout << "Sistema otimizado inicializado." << std::endl;

    while (running) {
        float currentTime = timer.getElapsedTime();
        
        // Event handling
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_F11) {
                    isFullscreen = !isFullscreen;
                    if (isFullscreen) {
                        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                    } else {
                        SDL_SetWindowFullscreen(window, 0);
                        SDL_SetWindowSize(window, 800, 600);
                    }
                    viewportNeedsUpdate = true;
                }
                else if (event.key.keysym.sym == SDLK_ESCAPE && isFullscreen) {
                    isFullscreen = false;
                    SDL_SetWindowFullscreen(window, 0);
                    SDL_SetWindowSize(window, 800, 600);
                    viewportNeedsUpdate = true;
                }
            }
            else if (event.type == SDL_WINDOWEVENT) {
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    windowWidth = event.window.data1;
                    windowHeight = event.window.data2;
                    viewportNeedsUpdate = true;
                    uniforms.resolutionDirty = true; // Marca resolução como dirty
                }
            }
        }

        // Atualiza viewport apenas quando necessário
        if (viewportNeedsUpdate) {
            SDL_GetWindowSize(window, &windowWidth, &windowHeight);
            glViewport(0, 0, windowWidth, windowHeight);
            viewportNeedsUpdate = false;
            glState.markDirty(); // Força refresh do estado OpenGL
        }

        // Hot reload assíncrono (sem overhead no loop principal)
        if (reloader.shouldReload()) {
            std::cout << "Recompilando shaders..." << std::endl;
            
            // Deleta programa anterior
            if (shader != 0) {
                glDeleteProgram(shader);
            }
            
            // Carrega e compila novos shaders
            vertSrc = loadShaderSource("vertex.vert");
            fragSrc = loadShaderSource("fragment.frag");
            GLuint newShader = createProgram(vertSrc.c_str(), fragSrc.c_str());
            
            if (newShader != 0) {
                shader = newShader;
                uniforms.updateLocations(shader);
                glState.markDirty(); // Força refresh do estado
                std::cout << "Shaders recompilados com sucesso!" << std::endl;
            } else {
                std::cout << "Erro na recompilação - mantendo shader anterior" << std::endl;
            }
            
            reloader.markReloaded();
        }
        
        // Rendering otimizado com cache de estado
        glClear(GL_COLOR_BUFFER_BIT);
        
        glState.useProgram(shader);
        glState.bindVertexArray(vao);
        
        // Atualiza uniforms apenas quando necessário
        uniforms.updateTime(currentTime);
        uniforms.updateResolution(static_cast<float>(windowWidth), static_cast<float>(windowHeight));
        
        glDrawArrays(GL_TRIANGLES, 0, 6);
        
        glState.markClean(); // Estado agora está limpo
        
        SDL_GL_SwapWindow(window);
    }

    // Cleanup
    fileWatcher.removeWatch(watchID);
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    if (shader != 0) {
        glDeleteProgram(shader);
    }
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}