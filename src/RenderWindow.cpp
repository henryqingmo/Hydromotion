#include "../include/RenderWindow.h"

RenderWindow::RenderWindow(const char *title, int w, int h) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // Use default graphics card and graphics driver
}
//SDL_Texture* RenderWindow::loadTexture(const char *file_path) {

//}

void RenderWindow::CleanUp() {
    SDL_DestroyWindow(window);
}
