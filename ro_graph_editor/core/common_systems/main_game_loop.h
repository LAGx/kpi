#pragma once
#include "../window.h"
#include "scene.h"
#include <memory>
#include "user_interface.h"
#include "event_system.h"


namespace ro {

    class MainGameLoop {
    public:

        struct Settings{
        public:
            ro::Window& window_handler;
            ro::EventSystem& event_system;
        };

        void setCurrentScene(std::shared_ptr<Scene>);

        void setCurrentUI(std::shared_ptr<UserInterface>);

        void Run(const Settings& );
    private:

        std::shared_ptr<Scene> current_scene = nullptr;
        std::shared_ptr<UserInterface> current_ui = nullptr;

    };

};