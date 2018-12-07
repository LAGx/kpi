#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <functional>

namespace ro {


    class IGameObject {
    public:

        IGameObject(int _id):id(_id)
            {}

        IGameObject() = delete;

        virtual ~IGameObject()
            {}

        const int id;

        virtual void draw(sf::RenderWindow &) = 0;

    };

};