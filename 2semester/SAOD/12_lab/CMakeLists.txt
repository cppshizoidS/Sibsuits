cmake_minimum_required(VERSION 3.20)
project(SAOD)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

add_executable(SAOD "src/main.cpp" "src/Hash.cpp")
target_include_directories(SAOD PUBLIC "include")
