cmake_minimum_required(VERSION 3.20)
project(Hydromotion)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_LINK_FLAGS "-lSDL2 -lSDL2_image")

add_executable(Hydromotion src/main.cpp src/RenderWindow.cpp include/RenderWindow.h)
