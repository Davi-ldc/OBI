#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erro ao inicializar SDL: " << SDL_GetError() << endl;
        return -1;
    }

    // Criar janela
    SDL_Window* window = SDL_CreateWindow(
        "Minha Janela SDL2",           // Título da janela
        SDL_WINDOWPOS_CENTERED,        // Posição X
        SDL_WINDOWPOS_CENTERED,        // Posição Y
        800,                           // Largura
        600,                           // Altura
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE             // Flags
    );

    if (window == nullptr) {
        cout << "Erro ao criar janela: " << SDL_GetError() << endl;
        SDL_Quit();
        return -1;
    }

    // Cria o renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        cout << "Erro ao criar renderer: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Loop principal
    bool running = true;
    SDL_Event event;

    while (running) {
        // Processar eventos
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Limpar tela (cor de fundo azul)
        SDL_SetRenderDrawColor(renderer, 0, 100, 200, 255);
        SDL_RenderClear(renderer);

        // Apresentar o frame
        SDL_RenderPresent(renderer);
    }

    // Limpar recursos
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
