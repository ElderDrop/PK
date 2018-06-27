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

/**
 * Gets properties from command line
 * @param argc      - quantity of arguments
 * @param argv      - arguments list
 * @param properties- properties to return
 * @return true     - if success
 *         false    - if failed
 */
bool getArguments(int argc, char **argv,struct GameOfLifeArguments* pArguments);

/**
 * Validate arguments
 * @param pArguments -  properties pointer
 * @return true     - if arguments are valid
 *         false    - if arguments are valid
 */
bool isLifePropertiesValid(struct GameOfLifeArguments *pArguments);

#endif //PROJEKT_GAMEOFLIFEARGUMENT_H
