#include "main_game_loop.h"
#include <iostream>

using namespace ro;
using namespace std;
using namespace sf;


void MainGameLoop::Run(const MainGameLoop::Settings& context){


    while (context.window_handler.native_handler().isOpen()) {

        context.event_system.update(context.window_handler);

        //context.window_handler.native_handler().clear();

        current_scene->draw(context.window_handler);
        current_ui->draw(context.window_handler);

        //context.window_handler.native_handler().display();
        context.window_handler.display();
    }
}



void MainGameLoop::setCurrentScene(std::shared_ptr<Scene> new_scene){
    current_scene = new_scene;
}


void MainGameLoop::setCurrentUI(std::shared_ptr<UserInterface> new_ui){
    current_ui = new_ui;
}