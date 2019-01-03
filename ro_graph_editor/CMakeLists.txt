cmake_minimum_required(VERSION 3.10)
project(ro_graph_editor)

set(CMAKE_CXX_STANDARD 17)

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
find_package (SFML REQUIRED system window graphics network audio)

add_executable(ro_graph_editor main.cpp core/window.h core/window.cpp core/common_systems/main_game_loop.h core/common_systems/main_game_loop.cpp core/common_types/igame_object.h core/common_systems/scene.h core/common_systems/user_interface.h core/common_systems/scene.cpp core/common_systems/user_interface.cpp core/common_systems/event_system.h core/common_systems/event_system.cpp core/game_objects/moveable_circle.hpp core/game_objects/camera.hpp core/common_types/sf_line_width.hpp)


target_link_libraries(ro_graph_editor ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
