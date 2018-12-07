#include "main_game_loop.h"

using namespace ro;
using namespace std;
using namespace sf;


void MainGameLoop::Run(const MainGameLoop::Settings& context){

    while (context.window_handler.native_handler().isOpen()) {



        context.window_handler.native_handler().clear();
        //window_handler.draw(shape);
        context.window_handler.native_handler().display();
    }
}