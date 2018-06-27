cmake_minimum_required(VERSION 3.10)
project(Projekt C)

set(CMAKE_C_STANDARD 11)
SET(CMAKE_C_FLAGS -pthread)


add_executable(Projekt main.c GameOfLife.c GameOfLife.h GameOfLifeArguments.c GameOfLifeArguments.h Ant.c Ant.h AntProperties.c AntProperties.h ThreadArg.h AntPath.c AntPath.h Mode.c Mode.h)