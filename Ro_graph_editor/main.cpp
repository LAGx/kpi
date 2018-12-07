#include <SFML/Graphics.hpp>
#include "core/window.h"
#include "core/main_game_loop.h"
#include "core/scene.h"

int main(){

    //init window system
    ro::Window::Settings window_settings;
    window_settings.name = "Ro Graph Editor";
    ro::Window window(window_settings);


    ro::Scene s();


    //init game loop system
    ro::MainGameLoop game_loop;
    ro::MainGameLoop::Settings game_loop_settings = {window};
    game_loop.Run(game_loop_settings);

    return 0;
}