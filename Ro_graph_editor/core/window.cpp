#include "window.h"


using namespace ro;
using namespace std;
using namespace sf;




ro::Window::Window(const ro::Window::Settings& settings):
    core_window(sf::VideoMode(settings.size.x, settings.size.y), settings.name){

}




sf::RenderWindow& ro::Window::native_handler(){
    return core_window;
}