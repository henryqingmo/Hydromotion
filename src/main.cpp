#include <iostream>
#include "RenderWindow.h"

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) //returns 0 if initialised properly
    {
        std::cout << "SDL INIT HAS FAILED" << SDL_GetError() << std::endl;
    }
    if(!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "IMG INIT HAS FAILED" << SDL_GetError() << std::endl;
    }
    RenderWindow window("Hydromotion", 1280, 720);

   bool QuitGame = false;

    SDL_Event event;

    while(!QuitGame)
    {
        while (SDL_PollEvent(&event) != 0) //1 for pending event and 0 for no event
        {
            if(event.type == SDL_QUIT)
            {
                QuitGame = true;
            }
        }
    }


    window.cleanUp();
    SDL_Quit();

    return 0;
}
