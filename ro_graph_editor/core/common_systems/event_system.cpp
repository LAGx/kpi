#include "event_system.h"
#include <iostream>

using namespace std;
using namespace ro;


void EventSystem::subscribe(std::shared_ptr<IAction> new_subs){
    subscribers.push_back(new_subs);
    subscribers_changes = true;
}


void EventSystem::unsubscribe(std::shared_ptr<IAction> old_subscriber){
    auto to_delete = find_if(subscribers.begin(), subscribers.end(), [&old_subscriber](const std::shared_ptr<IAction> & element){
       return element->id == old_subscriber->id;
    });

    if(to_delete != subscribers.end())
        subscribers.erase(to_delete);
    subscribers_changes = true;
}


void EventSystem::update(Window& window){

    window.native_handler().pollEvent(event);

    if (event.type == sf::Event::Closed)
        window.native_handler().close();

    if (event.type == sf::Event::TextEntered){
        for(auto& subscriber: subscribers){
            if(subscribers_changes == false)
                subscriber->onTextEnter(event.text.unicode);
        }
    }

    if (event.type == sf::Event::KeyPressed){
        for(auto& subscriber: subscribers){
            if(subscribers_changes == false){
                subscriber->onKeyPressed(event.key.code);
            }
        }
    }

   // if (event.type == sf::Event::MouseWheelScrolled ||
    //    event.type == sf::Event::MouseButtonPressed ||
    //    event.type == sf::Event::MouseMoved){
        if(event.type == sf::Event::MouseButtonPressed)
            mouse_button_state = event.mouseButton.button;
        if(event.type == sf::Event::MouseButtonReleased)
            mouse_button_state = sf::Mouse::Button::ButtonCount;

        sf::Vector2f position = window.native_handler().mapPixelToCoords(sf::Mouse::getPosition(window.native_handler()));

        for(auto& subscriber: subscribers){
            if(subscribers_changes == false){
                subscriber->onMouseAction(mouse_button_state, position , last_mouse_wheel_position - event.mouseWheelScroll.delta);
            }
        }

        last_mouse_wheel_position = event.mouseWheelScroll.delta;
    //}
        subscribers_changes = false;
}