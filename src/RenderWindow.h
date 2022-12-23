/* This header file defines prototype of classes and is modified in the corresponding cpp files
 * It allows other cpp files to create objects by including this header file.
 * */

#ifndef HYDROMOTION_RENDERWINDOW_H
#define HYDROMOTION_RENDERWINDOW_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    RenderWindow(const char* title, int w, int h);
    void cleanUp();

};


#endif //HYDROMOTION_RENDERWINDOW_H
