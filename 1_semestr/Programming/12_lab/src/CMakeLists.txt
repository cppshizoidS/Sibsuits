cmake_minimum_required(VERSION 3.27.4)

project(lab12)

add_executable(lab12 main.cpp)

target_link_libraries(lab12 sfml-graphics)
target_link_libraries(lab12 sfml-window)
target_link_libraries(lab12 sfml-system)
