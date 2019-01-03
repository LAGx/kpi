#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
#include "../common_systems/event_system.h"
#include "../window.h"

namespace ro {


    class IGameObject: public EventSystem::IAction{
    public:

        IGameObject(int _id):IAction(_id), id(_id)
            {}

        IGameObject() = delete;

        virtual ~IGameObject()
            {}

        const int id;

        virtual void draw(Window&) = 0;

        bool is_alive = true;
    };

};