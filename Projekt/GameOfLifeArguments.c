#include "GameOfLifeArguments.h"
#include <stdlib.h>
#include <string.h>

bool isLifePropertiesValid(struct GameOfLifeArguments *pProperties) {
    if(pProperties->lastCycle == 0)
        return false;
    if(pProperties->endBoardFileName == NULL || pProperties->endBoardFileName[0] == '\0')
        return false;
    if(pProperties->startBoardFileName == NULL || pProperties->startBoardFileName[0] == '\0')
        return false;
    if(pProperties->width == 0)
        return false;
    if(pProperties->height == 0)
        return false;
    return true;
}

bool getArguments(int argc, char **argv, struct GameOfLifeArguments *pArguments) {

    if (argc != 12)
    {
        return false;
    }

    for(int i = 2; i < argc;i++)
    {
        if(strcmp("-i",argv[i]) == 0)
        {
            pArguments->startBoardFileName = argv[++i];
        }
        if(strcmp("-o",argv[i]) == 0)
        {
            pArguments->endBoardFileName = argv[++i];
        }
        if(strcmp("-c",argv[i]) == 0)
        {
            pArguments->lastCycle = (unsigned int)atoi(argv[++i]);
        }
        if(strcmp("-w",argv[i]) == 0)
        {
            pArguments->width = (unsigned int)atoi(argv[++i]);
        }
        if(strcmp("-t",argv[i]) == 0)
        {
            pArguments->height = (unsigned int)atoi(argv[++i]);
        }
        if(strcmp("-h",argv[i]) == 0)
        {
            return false;
        }
    }
    return isLifePropertiesValid(pArguments);
}

