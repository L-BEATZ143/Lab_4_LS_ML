cmake_minimum_required(VERSION 3.16)

project(receipt_template VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(receipt_app
    main.cpp
    src/receipt.cpp
)

target_include_directories(receipt_app PRIVATE include)

if (MSVC)
    target_compile_options(receipt_app PRIVATE /W4)
else()
    target_compile_options(receipt_app PRIVATE -Wall -Wextra -Wpedantic)
endif()