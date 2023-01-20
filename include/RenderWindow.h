/* This header file defines prototype of classes and is modified in the corresponding cpp files
 * It allows other cpp files to create objects by including this header file.
 * */

#ifndef HYDROMOTION_RENDERWINDOW_H // The include guard ensures the file is processed only once.
#define HYDROMOTION_RENDERWINDOW_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <QWidget>

class RenderWindow
{
private:
    SDL_Window* m_sdlWindow;
    QWidget m_qtWindow;
    SDL_Renderer* m_renderer;
public:
    RenderWindow(const QString title, int w, int h);
    SDL_Texture* loadTexture(const char* file_path);
    void cleanUp();
    void clear();
    void render(SDL_Texture* texture);
    void display();
    

};


#endif //HYDROMOTION_RENDERWINDOW_H
