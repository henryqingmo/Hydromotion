#include "../include/RenderWindow.h"

RenderWindow::RenderWindow(const char *title, int w, int h) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // Use default graphics card and graphics driver
}
SDL_Texture* RenderWindow::loadTexture(const char* file_path) // SDL_Texture* is the identifier, this line calls the function loadTexture;
{
    SDL_Texture* texture = IMG_LoadTexture(renderer, file_path);
    return texture;
    
};

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* texture)
{
    SDL_RenderCopy(renderer, texture, NULL, NULL);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

    

void RenderWindow::cleanUp() {
    SDL_DestroyWindow(window);
}
