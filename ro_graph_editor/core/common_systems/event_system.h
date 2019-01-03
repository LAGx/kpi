#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include "../window.h"

namespace ro {


    class EventSystem{
    public:

        class IAction{
        public:

            IAction(int _id): id(_id)
                {}

            const int id;

            virtual void onKeyPressed(sf::Keyboard::Key)
                {}

            virtual void onMouseAction(sf::Mouse::Button, sf::Vector2f position, float weel_delta)
                {}

            virtual void onTextEnter(unsigned int)
                {}
        };

        void subscribe(std::shared_ptr<IAction>);

        void unsubscribe(std::shared_ptr<IAction>);

        void update(Window &);

    private:

        sf::Event event;

        std::vector<std::shared_ptr<IAction>> subscribers;

        sf::Mouse::Button mouse_button_state;
        float last_mouse_wheel_position = 0;
        bool subscribers_changes = false;
    };

};