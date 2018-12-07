#pragma once
#include "window.h"

namespace ro {

    class MainGameLoop {
    public:

        struct Settings{
        public:
            ro::Window& window_handler;
        };

        void Run(const Settings& );

    };

};