cmake_minimum_required(VERSION 3.20)
project(10_lab)

# doxygen
if(DOCS)
  add_subdirectory(docs)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
  ${PROJECT_NAME} src/main.cpp include/BaseListFunc.hpp include/List.hpp
                  include/Queue.hpp include/Stack.hpp include/Node.hpp
)
