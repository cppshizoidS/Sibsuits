cmake_minimum_required(VERSION 3.27)
project(Cursach)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/cppshizoid/Documents/Programming/Cpp/Qt6/Cursach")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Cursach main.cpp)
target_link_libraries(Cursach
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

