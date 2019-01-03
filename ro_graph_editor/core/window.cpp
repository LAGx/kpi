#include "window.h"
#include <iostream>

using namespace ro;
using namespace std;



ro::Window::Window(const ro::Window::Settings& settings):
    core_window(sf::VideoMode(settings.size.x, settings.size.y), settings.name, sf::Style::Close){

}


void Window::draw(Window::RenderObject obj){
	all_to_draw.push_back(obj);
}
 

void Window::display(){
	core_window.clear();

	sort(all_to_draw.begin(), all_to_draw.end(), [](const Window::RenderObject& a, const Window::RenderObject& b)->bool{
		return a.depth > b.depth;
	});

	for(auto& to_draw: all_to_draw){
		if(to_draw.drawable != nullptr)
			core_window.draw(*(to_draw.drawable));
	}

	core_window.display();
	all_to_draw.clear();
}

Window::RenderObject& Window::RenderObject::operator=(const Window::RenderObject& another){
	drawable = another.drawable;
	depth = another.depth;
	return *this;
}


sf::RenderWindow& ro::Window::native_handler(){
    return core_window;
}