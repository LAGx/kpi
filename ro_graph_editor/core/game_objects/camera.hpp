#pragma once
#include "../common_types/igame_object.h"
#include <SFML/Graphics.hpp>
#include <numeric>
#include <iostream>
#include <cmath>


namespace ro {

    class Camera: public IGameObject {
    public:

        
        Camera(int id): IGameObject(id), view(sf::FloatRect(0,0,900,500))
        	{}


        void onMouseAction(sf::Mouse::Button button, sf::Vector2f position, float weel_delta) override{
            
            if(button == sf::Mouse::Button::Middle){
                view.setCenter(view.getCenter() + ((last_mouse_position - position) * move_speed * (float)zoom_factor));
                last_mouse_position = position + ((last_mouse_position - position) * move_speed * (float)zoom_factor);
            }else{
                last_mouse_position = position;
            }

            if(std::numeric_limits<float>::epsilon() < abs(weel_delta)){
            	zoom_factor += weel_delta * zoom_speed;
            	view.zoom(zoom_factor);
            } 
        }


        void draw(Window& window) override {
           window.native_handler().setView(view);
        }


    protected:
    	sf::View view;
    	double zoom_factor = 1.0f;
    	double zoom_speed = 0.08f;

        sf::Vector2f last_mouse_position;
        float move_speed = 1.0f;
    };

};




