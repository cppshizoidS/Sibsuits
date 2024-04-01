cmake_minimum_required(VERSION 3.20)
project(9_lab)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} ArrFunc.hpp Sorts.hpp main.cpp)
