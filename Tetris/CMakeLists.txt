cmake_minimum_required(VERSION 3.20)
project(Tetris)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CROSSCOMPILING true)
#set(CMAKE_SYSTEM_NAME Windows)
#set(CMAKE_SYSTEM_VERSION 10.0)
include_directories(.)
add_executable(Tetris
        main.cpp
        Game.cpp
        Game.h
        Grid.h
        Grid.cpp
        Tetromino.cpp
        Tetromino.h
        Mino.hpp
        Constants.h
        )

target_link_libraries (Tetris sfml-graphics sfml-window sfml-audio sfml-network sfml-system)

