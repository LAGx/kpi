#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "event_system.h"

namespace ro{

    class UserInterface{
    private:
        EventSystem& event_system;
    public:

        UserInterface(EventSystem&);

        UserInterface() = delete;

        void draw(Window &);
    };

};
