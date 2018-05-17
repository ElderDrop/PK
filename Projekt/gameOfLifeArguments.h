#ifndef PROJEKT_GAMEOFLIFEARGUMENT_H
#define PROJEKT_GAMEOFLIFEARGUMENT_H

#include <stdbool.h>

struct GameOfLifeArguments {
    char* startBoardFileName;
    char* endBoardFileName;
    unsigned int lastCycle ;
    unsigned int width;
    unsigned int height;
};

bool getArguments(int argc, char **argv,struct GameOfLifeArguments* pArguments);

bool isLifePropertiesValid(struct GameOfLifeArguments *pArguments);

#endif //PROJEKT_GAMEOFLIFEARGUMENT_H
