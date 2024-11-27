cmake_minimum_required(VERSION 3.29)
project(Minesweeper)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_CXX_STANDARD 20)

add_executable(Minesweeper main.cpp
        Random.cpp
        TextureManager.cpp
        Board.cpp
        Board.h
        Tile.cpp
        Tile.h
        Window.cpp
        Window.h
        Worker.cpp
        Worker.h
)

include_directories(/opt/homebrew/)

find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Minesweeper sfml-system sfml-window sfml-graphics sfml-audio sfml-network)