cmake_minimum_required(VERSION 3.20)

project(tamagotchi C)

set(CMAKE_C_STANDARD 11)

find_package(SDL2 REQUIRED)

add_executable(tamagotchi
    src/main.c
)

target_link_libraries(tamagotchi PRIVATE SDL2::SDL2)