#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>

namespace ro{


    class Window{
    public:

        struct Settings{
        public:
            Settings():size(900,500) {}

            std::string name = "sfml window";
            sf::Vector2i size;
        };


        Window(const Settings&);

        struct RenderObject{
            sf::Drawable* drawable = nullptr;
            int depth = 0;
            RenderObject& operator=(const RenderObject& another);
        };

        void draw(RenderObject);

        void display();

        sf::RenderWindow& native_handler();

    private:

        std::vector<RenderObject> all_to_draw;

        sf::RenderWindow core_window;

    };
};