/** @file  */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GameOfLife.h"
#include "Ant.h"
#include "Mode.h"

int main(int argc,char **argv)
{
    //Set up
    if (argc == 1)
    {
        help();
        return 0;
    }
    //Game mode
    int gameMode = mode(argv[1]);
    void (*gameFunction)(void*);
    //Error show help
    if(gameMode == 0)
    {
        help();
        return 0;
    }
    else if(gameMode == 1)
    {
        // Prepare arguments for the game
        struct GameOfLifeArguments properties;
        // If error show help
        if(!getArguments(argc,argv,&properties))
        {
            help();
            return 0;
        }
        gameFunction = gameOfLife;
        // Do game
        gameFunction(&properties);
    }
    else if(gameMode == 2)
    {
        // Prepare arguments for the game
        struct AntProperties properties;
        // If error show help
        if(!getAntArguments(argc,argv,&properties))
        {
            help();
            return 0;
        }
        // Do game
        gameFunction = antGame;

        gameFunction(&properties);
    }

    return 0;
}