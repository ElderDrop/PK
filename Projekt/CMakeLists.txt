cmake_minimum_required(VERSION 3.10)
project(Projekt C)

set(CMAKE_C_STANDARD 11)
SET(CMAKE_C_FLAGS -pthread)


add_executable(Projekt main.c gameOfLife.c gameOfLife.h gameOfLifeArguments.c gameOfLifeArguments.h Ant.c Ant.h AntProperties.c AntProperties.h ThreadArg.h)