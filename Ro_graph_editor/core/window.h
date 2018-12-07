#pragma once
#include <SFML/Graphics.hpp>
#include <string>

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

        sf::RenderWindow& native_handler();

    private:

        sf::RenderWindow core_window;

    };
};