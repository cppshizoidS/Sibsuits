cmake_minimum_required(VERSION 3.20)
project(11_lab)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab src/main.cpp)

include_directories(/usr/local/include)

find_package(
  SFML 2.5
  COMPONENTS graphics
  REQUIRED)

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(Lab sfml-graphics sfml-window sfml-system)
endif()
