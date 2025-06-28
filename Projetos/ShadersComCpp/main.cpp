#include <SDL.h>
#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <chrono>

std::string loadShaderSource(const char* filename) {
    std::ifstream file(filename);
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
    glDeleteShader(vs);
    glDeleteShader(fs);
    return program;
}

std::filesystem::file_time_type getFileTime(const char* filename) {
    return std::filesystem::last_write_time(filename);
}

int SDL_main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("GLSL + SDL2 (Hot Reload)", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(window);
    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

    // Shader hot reload
    auto lastVertTime = getFileTime("vertex.glsl");
    auto lastFragTime = getFileTime("fragment.glsl");
    
    std::string vertSrc = loadShaderSource("vertex.glsl");
    std::string fragSrc = loadShaderSource("fragment.glsl");
    GLuint shader = createProgram(vertSrc.c_str(), fragSrc.c_str());

    float vertices[] = {
        -1, -1,  1, -1,  1,  1,
        -1, -1,  1,  1, -1,  1
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
    SDL_Event event;
    float t = 0;

    while (running) {
        while (SDL_PollEvent(&event)) if (event.type == SDL_QUIT) running = false;

        // Hot reload check
        auto currentVertTime = getFileTime("vertex.glsl");
        auto currentFragTime = getFileTime("fragment.glsl");
        
        if (currentVertTime != lastVertTime || currentFragTime != lastFragTime) {
            std::cout << "Shaders changed, reloading..." << std::endl;
            glDeleteProgram(shader);
            
            vertSrc = loadShaderSource("vertex.glsl");
            fragSrc = loadShaderSource("fragment.glsl");
            shader = createProgram(vertSrc.c_str(), fragSrc.c_str());
            
            lastVertTime = currentVertTime;
            lastFragTime = currentFragTime;
        }

        t += 0.016f;
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shader);
        glUniform1f(glGetUniformLocation(shader, "time"), t);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}