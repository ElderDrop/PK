#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gameOfLife.h"
#include "Ant.h"

/**
 * Help
 */
void help()
{
    printf("Pomoc: \n");
    printf("Wybierz tryb gry poprzez -g dla gry w zycie lub -m dla mrowki\n");
}
/**
 *
 * @param argument
 * @return 0 - error mode
 *         1 - game in life
 *         2 - ant game
 */
unsigned int mode(const char* argument)
{
    if(strcmp("-g",argument) == 0)
        return 1;
    if(strcmp("-m",argument) == 0)
        return 2;
    return 0;
}

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
        // Do game
        gameOfLife(&properties);
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
        antGame(&properties);
    }
    return 0;
}