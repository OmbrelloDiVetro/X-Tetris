cmake_minimum_required(VERSION 3.23)
project(tetris_2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(tetris_2
        dataType.h
        main.c
        menu.c
        menu.h
        mode.c
        mode.h
        strategy.c
        strategy.h
        turn.c
        turn.h)
