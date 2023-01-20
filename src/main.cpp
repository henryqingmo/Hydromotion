#include <QApplication>
#include <QWidget>
#include "../include/MainMenu.h"
#include "../include/RenderWindow.h"
#include "../include/Log.h"
//#include "../include/main.h"

int main(int argc, char* argv[]) {
    LOG Log;
    Log.setLevel(LOG::LevelInfo);

    QApplication a(argc, argv);
    //MainMenu w;
    //w.setTexture("../res/background.jpeg");
    //w.show();


    if (SDL_Init(SDL_INIT_VIDEO) != 0) //returns 0 if initialised properly
    {
        Log.getLog(LOG::LevelError, "SDL Init Failed", SDL_GetError());
    }
   if  (IMG_Init(IMG_INIT_PNG) < 0)
   {
       Log.getLog(LOG::LevelError, "SDL_IMG Init Failed", SDL_GetError());
   }
    //QWidget MainWindow;
    //MainWindow.resize(640, 480);
    //MainWindow.setWindowTitle("SDL");
    //MainWindow.show();
    //SDL_Window *sdl_window = SDL_CreateWindowFrom((void*)MainWindow.winId());

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


    return a.exec();
    return 0;
}
