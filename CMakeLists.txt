cmake_minimum_required(VERSION 3.16)

project(cpp_starter_app VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cpp_starter_app main.cpp)

if (MSVC)
    target_compile_options(cpp_starter_app PRIVATE /W4)
else()
    target_compile_options(cpp_starter_app PRIVATE -Wall -Wextra -Wpedantic)
endif()