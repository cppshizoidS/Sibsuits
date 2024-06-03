cmake_minimum_required(VERSION 3.20)
project(11_lab)

if(DOCS)
  add_subdirectory(docs)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} src/main.cpp)
