cmake_minimum_required(VERSION 3.20)
project(1_task)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} my_vector.hpp my_list.hpp my_binary_tree.hpp my_functional.hpp my_search.hpp my_strcmp.hpp my_is_same.hpp my_copy.hpp my_move.hpp my_swap.hpp my_min.hpp my_same_as.hpp my_string.hpp main.cpp)
