cmake_minimum_required(VERSION 3.27.4)

project(lab11)

add_executable(lab11 main.cpp)

target_link_libraries(lab11 sfml-graphics)
target_link_libraries(lab11 sfml-window)
target_link_libraries(lab11 sfml-system)
