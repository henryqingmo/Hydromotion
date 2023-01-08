#include <QApplication>
#include "../include/MenuScreen.h"
#include "../include/RenderWindow.h"
#include "../include/Log.h"


int main(int argc, char* argv[]) {

    QApplication a(argc, argv);
    MenuScreen w;
    w.show();
    return a.exec();
    LOG Log;
    Log.setLevel(LOG::LevelInfo);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) //returns 0 if initialised properly
    {
        Log.getLog(LOG::LevelError, "SDL Init Failed", SDL_GetError());
    }
   if  (IMG_Init(IMG_INIT_PNG) < 0)
   {
       Log.getLog(LOG::LevelError, "SDL_IMG Init Failed", SDL_GetError());
   }
    RenderWindow window("Hydromotion", 1280, 720);
    
    SDL_Texture* background = window.loadTexture("/home/henry/Documents/Programming/Project/Hydromotion/res/background.jpeg");
   


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
