#pragma once
#include <vector>
#include <memory>
#include "../common_types/igame_object.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "event_system.h"
#include <algorithm>
#include "../game_objects/moveable_circle.hpp"
#include "../game_objects/camera.hpp"
#include <stdlib.h> 
#include <time.h> 


namespace ro {
    class Scene;

    class Scene: public std::enable_shared_from_this<Scene>, public EventSystem::IAction {
    public:

        Scene(EventSystem&);

        Scene() = delete;

        ~Scene();

        void draw(Window &);

        void add(std::shared_ptr<ro::IGameObject>);

        void remove(std::shared_ptr<ro::IGameObject> old_go);

        void onKeyPressed(sf::Keyboard::Key) override;

        void onMouseAction(sf::Mouse::Button, sf::Vector2f position, float weel_delta) override;

    private:

        EventSystem& event_system;

        std::vector<std::shared_ptr<ro::IGameObject>> all_objects;

        int generateId();
        int last_id = 2;

        sf::Vector2f last_mouse_position;
    };

};