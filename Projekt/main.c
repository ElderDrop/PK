#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gameOfLife.h"

void help()
{
    printf("Pomoc: \n");
    printf("Wybierz tryb gry poprzez -g dla gry w zycie lub -m dla mrowki\n");
}

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
    int gameMode = mode(argv[1]);
    if(gameMode == 0)
    {
        help();
        return 0;
    }
    if(gameMode == 1)
    {
        struct GameOfLifeArguments properties;
        if(!getArguments(argc,argv,&properties))
        {
            help();
            return 0;
        }
        gameOfLife(&properties);
    }
    return 0;
}