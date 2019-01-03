#include "scene.h"


using namespace std;
using namespace ro;



Scene::Scene(EventSystem& e_S): event_system(e_S), EventSystem::IAction(1) {
    add(shared_ptr<Camera>(new Camera(2)));
    srand (time(NULL));
}


Scene::~Scene(){
}


void Scene::draw(Window& window) {

    for(auto& element: all_objects)
        element->draw(window);

    for(auto& element: all_objects){
        if(!element->is_alive){
            remove(element);
            break;
        }
    }
}


void Scene::add(shared_ptr<ro::IGameObject> new_go){
    all_objects.push_back(new_go);
    event_system.subscribe(dynamic_pointer_cast<EventSystem::IAction>(new_go));
}


void Scene::remove(shared_ptr<ro::IGameObject> old_go){

    auto old_go_iter = find_if(all_objects.begin(), all_objects.end(), [&old_go](const shared_ptr<ro::IGameObject>& element){
        return element->id == old_go->id;
    });

    if(old_go_iter != all_objects.end()) {
        event_system.unsubscribe(dynamic_pointer_cast<EventSystem::IAction>(*old_go_iter));
        all_objects.erase(old_go_iter);
    }
}


void Scene::onKeyPressed(sf::Keyboard::Key key) {
    if(key == sf::Keyboard::Key::N){
        add(shared_ptr<ro::IGameObject>((ro::IGameObject*)(new MoveableCircle(generateId(), 50, last_mouse_position, {0,rand() % 150,255}))));
    }
}

void Scene::onMouseAction(sf::Mouse::Button, sf::Vector2f position, float weel_delta) {
    last_mouse_position = position;
}


int Scene::generateId(){
    last_id++;
    return last_id;
}
