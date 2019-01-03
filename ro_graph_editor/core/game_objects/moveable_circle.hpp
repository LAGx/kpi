#pragma once
#include "../common_types/igame_object.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <utility>
#include <memory>
#include <algorithm>
#include <iostream>
#include "../common_types/sf_line_width.hpp"

namespace ro {

    class MoveableCircle: public IGameObject {
    public:

        const int RADIUS_EPSILON = 2;

        class ConnectorTriangle: public sf::Drawable{

        public:

            ConnectorTriangle(float _width = 1, sf::Vector2f init_A = {0,0}, sf::Vector2f init_B = {1,1}, sf::Color _color = {0,255,0}, float add_offset = 0,
                float subject_radius = 0):
            width(_width),
            A(init_A),
            B(init_B)
            {
                setColor(_color);
                setAdditionalOffset(add_offset);
                setSubjectRadius(subject_radius);
            }


            void setA(sf::Vector2f vec){
                A = vec;
            }

            void setB(sf::Vector2f vec){
                B = vec;
            }

            void setColor(sf::Color col){
                for(int i = 0; i < 4; i++)
                    triangle[i].color = col;
            }

            void setAdditionalOffset(float offset){
                aditional_offset = offset;
            }

            void setSubjectRadius(float radius){
                subject_radius = radius;
            }

            void update(){
                
                sf::Vector2f direction = A - B;
                sf::Vector2f unitDirection = direction/std::sqrt(direction.x*direction.x+direction.y*direction.y);
                sf::Vector2f unitPerpendicular(-unitDirection.y,unitDirection.x);

                sf::Vector2f offset = (width/2.f)*unitPerpendicular;

                triangle[0].position = B + offset*4.0f + normalize(direction)*1.3f*subject_radius;
                triangle[1].position = B - offset*4.0f + normalize(direction)*1.3f*subject_radius;
                triangle[2].position = B + normalize(direction)*0.8f*subject_radius;

                for(int i = 0; i < 3; i++){
                    triangle[i].position += offset * aditional_offset;
                }
                

            }

            double magnitude(const sf::Vector2f& vec){
                return sqrt(vec.x * vec.x + vec.y * vec.y);
            }

            sf::Vector2f normalize(const sf::Vector2f& vec){
                return {vec.x/magnitude(vec), vec.y/magnitude(vec)};
            }
        
        private:
            
            float width;
            float aditional_offset = 1;
            float subject_radius = 5;

            sf::Vector2f A;
            sf::Vector2f B;
        
            sf::Vertex triangle[4];

            void draw(sf::RenderTarget& target,sf::RenderStates states)const override{
                target.draw(triangle, 3, sf::Triangles);
            }

        };


        MoveableCircle(int id, double _radius = 10, sf::Vector2f _start_position = {0,0}, sf::Color _color = {0,255,0}):
                radius(_radius),
                IGameObject(id){

            circle.setOrigin(radius, radius);
            circle.setPosition(_start_position);
            circle.setRadius(radius);
            circle.setFillColor(_color);
            circle.setOutlineThickness(6);
            circle.setOutlineColor(sf::Color(25,120,25));
        }


        void onMouseAction(sf::Mouse::Button button, sf::Vector2f position, float weel_delta) override{

            if(phisic_isInCircle(position))
                circle_under_mouse = this;

            if(button == sf::Mouse::Button::Left){
                if(phisic_isInCircle(position) && !MoveableCircle::captured_move_now_by_another){
                    is_mouse_captured = true;
                    MoveableCircle::captured_move_now_by_another = true;
                    MoveableCircle::id_select_circle_handler = this->id;
                    selected_id_connection = -1;
                }else{
                    if(!MoveableCircle::captured_move_now_by_another){
                        for(auto& connection: connections){
                            if(std::get<1>(connection).phisic_isInLine(position)){
                                selected_id_connection = std::get<1>(connection).id;
                                MoveableCircle::id_select_circle_handler = this->id;
                                break;
                            }
                        }
                    }
                }
            }else{
                is_mouse_captured = false;
                MoveableCircle::captured_move_now_by_another = false;
            }
            


            if(is_mouse_captured) 
                circle.setPosition(position);

            if(button == sf::Mouse::Button::Right){
                if(phisic_isInCircle(position) && MoveableCircle::id_captured_connection == -1){
                    mock_connection.reset(new std::pair<std::unique_ptr<MoveableCircle>, sf::LineShape>(std::unique_ptr<MoveableCircle>(new MoveableCircle(0, 2, position)), sf::LineShape(-1, 5.0f, sf::Vector2f(0,0),sf::Vector2f(0,0), sf::Color(25,120,25))));     
                    MoveableCircle::id_captured_connection = id;                      
                }
            }else if(MoveableCircle::id_captured_connection == id){
                mock_connection = nullptr;
                MoveableCircle::id_captured_connection = -1;
                if(circle_under_mouse != nullptr && circle_under_mouse->id != this->id){
                    if(connections.end() == find_if(connections.begin(), connections.end(), [this, circle_under_mouse](const std::tuple<MoveableCircle*, sf::LineShape, ConnectorTriangle>& el){
                        return this->id == std::get<0>(el)->id || circle_under_mouse->id == std::get<0>(el)->id;
                    })){
                        connections.push_back(std::tuple<MoveableCircle*, sf::LineShape, ConnectorTriangle>(                circle_under_mouse, 
                                                                                                                            sf::LineShape(get_next_id_connection(), 5, {0,0}, {0,0}, {0,150,150}, 3.0f),
                                                                                                                            ConnectorTriangle(5, {0,0}, {0,0}, {50,250,50}, 3.0f, circle_under_mouse->radius)));
                    }
                }
            }

            if(mock_connection != nullptr)
                mock_connection->first->circle.setPosition(position);

        }


        void onKeyPressed(sf::Keyboard::Key key) override{
            if(key == sf::Keyboard::Key::D){
                if(MoveableCircle::id_select_circle_handler == this->id && selected_id_connection == -1){ 
                    //delete circle

                    connections.clear();
                    MoveableCircle::id_select_circle_handler = -1;
                    is_alive = false;

                }else if(MoveableCircle::id_select_circle_handler == this->id && selected_id_connection != -1){
                    //delete connection

                    connections.erase(std::remove_if(connections.begin(), connections.end(), [=](std::tuple<MoveableCircle*, sf::LineShape, ConnectorTriangle>& tp){
                        return std::get<1>(tp).id == selected_id_connection;
                    }), connections.end());

                }
            }
        }



        void draw(Window & window) override {

            if(MoveableCircle::id_select_circle_handler == this->id && selected_id_connection == -1){
                circle.setOutlineColor(sf::Color(55,255,55));
                circle.setOutlineThickness(8);
            }else{
                circle.setOutlineColor(sf::Color(25,120,25));
                circle.setOutlineThickness(6);
            }


            connections.erase(std::remove_if(connections.begin(), connections.end(), [](std::tuple<MoveableCircle*, sf::LineShape, ConnectorTriangle>& tp){
                return std::get<0>(tp)->is_alive == false;
            }), connections.end());


            for(auto& connector_subject: connections){

                if(std::get<1>(connector_subject).id == selected_id_connection && MoveableCircle::id_select_circle_handler == this->id){
                    std::get<1>(connector_subject).setColor({55,255,55});
                }else{
                    std::get<1>(connector_subject).setColor({0,150,150});
                }
                

                sf::Vector2f A = circle.getPosition();
                sf::Vector2f B = std::get<0>(connector_subject)->circle.getPosition();

                std::get<1>(connector_subject).setA(A);
                std::get<1>(connector_subject).setB(B);
                std::get<1>(connector_subject).update();

                window.draw({&std::get<1>(connector_subject), 100});

                

                std::get<2>(connector_subject).setA(A);
                std::get<2>(connector_subject).setB(B);
                std::get<2>(connector_subject).update();

                window.draw({&std::get<2>(connector_subject), 0});
            }
          
          

            if(mock_connection != nullptr){

                mock_connection->second.setA(circle.getPosition());
                mock_connection->second.setB(mock_connection->first->circle.getPosition());
                mock_connection->second.update();

                window.draw({&(mock_connection->second), 20});
            }

            window.draw({&circle, 10});
        }


        bool phisic_isInCircle(sf::Vector2f position){
            return magnitude(position - circle.getPosition()) < (radius + RADIUS_EPSILON);
        }


        double magnitude(const sf::Vector2f& vec){
            return sqrt(vec.x * vec.x + vec.y * vec.y);
        }

        sf::Vector2f normalize(const sf::Vector2f& vec){
            return {vec.x/magnitude(vec), vec.y/magnitude(vec)};
        }

        ~MoveableCircle(){
            if(circle_under_mouse != nullptr && circle_under_mouse->id == this->id)
                circle_under_mouse = nullptr;
        }

    protected:

        sf::CircleShape circle;
        double radius;

        std::vector<std::tuple<MoveableCircle*, sf::LineShape, ConnectorTriangle>> connections;
        std::unique_ptr<std::pair<std::unique_ptr<MoveableCircle>, sf::LineShape>> mock_connection = nullptr;

    private:

        float connection_width = 5;

        bool is_mouse_captured = false;
        bool creating_connection_stage = false;
        inline static bool captured_move_now_by_another = false;
        inline static int id_captured_connection = -1;

        inline static MoveableCircle* circle_under_mouse = nullptr;

        inline static int id_select_circle_handler = -1;

        int last_id_connection = 1;
        int get_next_id_connection(){
            last_id_connection++;
            return last_id_connection;
        }

        int selected_id_connection = -1;
    };

};