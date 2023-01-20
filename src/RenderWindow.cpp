#include "../include/RenderWindow.h"

RenderWindow::RenderWindow(const QString title, int w, int h) {
   // m_sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    m_qtWindow.resize(w, h);
    m_qtWindow.setWindowTitle(title);
    m_sdlWindow = SDL_CreateWindowFrom((void*)m_qtWindow.winId());
    m_renderer = SDL_CreateRenderer(m_sdlWindow, -1, SDL_RENDERER_ACCELERATED); // Use default graphics card and graphics driver
}
SDL_Texture* RenderWindow::loadTexture(const char* file_path) // SDL_Texture* is the identifier, this line calls the function loadTexture;
{
    SDL_Texture* texture = IMG_LoadTexture(m_renderer, file_path);
    return texture;
    
};

void RenderWindow::clear()
{
    SDL_RenderClear(m_renderer);
}

void RenderWindow::render(SDL_Texture* texture)
{
    SDL_RenderCopy(m_renderer, texture, nullptr, nullptr);
}

void RenderWindow::display()
{
    m_qtWindow.show();
    SDL_RenderPresent(m_renderer);
}


void RenderWindow::cleanUp() {
    SDL_DestroyWindow(m_sdlWindow);
}
