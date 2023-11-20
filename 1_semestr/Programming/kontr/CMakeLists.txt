cmake_minimum_required(VERSION 3.27.4)

project(kontr)

add_executable(kontr src/main.cpp)

target_link_libraries(kontr sfml-graphics)
target_link_libraries(kontr sfml-window)
target_link_libraries(kontr sfml-system)