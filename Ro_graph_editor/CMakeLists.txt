cmake_minimum_required(VERSION 3.12)
project(Ro_graph_editor)

set(CMAKE_CXX_STANDARD 17)

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
find_package (SFML REQUIRED system window graphics network audio)

add_executable(Ro_graph_editor main.cpp core/window.h core/window.cpp core/main_game_loop.h core/main_game_loop.cpp core/common_types/igame_object.h core/scene.h)


target_link_libraries(Ro_graph_editor ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})