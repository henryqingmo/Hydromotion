#include <iostream>
#include "../include/RenderWindow.h"

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) //returns 0 if initialised properly
    {
        std::cout << "SDL INIT HAS FAILED" << SDL_GetError() << std::endl;
    }
    IMG_Init(IMG_INIT_PNG);
    RenderWindow window("Hydromotion", 1280, 720);
    
    SDL_Texture* background = window.loadTexture("res/background.png");
   


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
        window.clear();
        window.render(background);
        window.display();
    }


    window.cleanUp();
    SDL_Quit();
    

    return 0;
}
