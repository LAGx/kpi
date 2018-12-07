#pragma once
#include <list>
#include <memory>
#include "common_types/igame_object.h"
#include <SFML/Graphics.hpp>


namespace ro {

    class Scene {
    public:

        void draw(sf::RenderWindow &);

        void push(std::unique_ptr<ro::IGameObject>);

        std::unique_ptr<ro::IGameObject> pop(int id);

    private:

        std::list<std::unique_ptr<ro::IGameObject>> all_objects;

    };

};