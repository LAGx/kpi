#include <SFML/Graphics.hpp>
#include "core/window.h"
#include "core/common_systems/main_game_loop.h"
#include "core/common_systems/scene.h"
#include <memory>
#include "core/common_systems/event_system.h"

int main(){

    //init window system
    ro::Window::Settings window_settings;
    window_settings.name = "Ro Graph Editor";
    ro::Window window(window_settings);

    ro::EventSystem event_system;


    std::shared_ptr<ro::Scene> main_scene( new ro::Scene(event_system));
    event_system.subscribe(std::dynamic_pointer_cast<ro::EventSystem::IAction>(main_scene));
    std::shared_ptr<ro::UserInterface> main_interface( new ro::UserInterface(event_system));


    //init game loop system
    ro::MainGameLoop game_loop;
    ro::MainGameLoop::Settings game_loop_settings = {window, event_system};

    game_loop.setCurrentScene(main_scene);
    game_loop.setCurrentUI(main_interface);

    game_loop.Run(game_loop_settings);

    return 0;
}