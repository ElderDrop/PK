#ifndef PROJEKT_GAMEOFLIFEARGUMENT_H
#define PROJEKT_GAMEOFLIFEARGUMENT_H

#include <stdbool.h>
/** Contains data for game of life game*/
struct GameOfLifeArguments {
    /** Input file name */
    char* startBoardFileName;
    /** Output file name*/
    char* endBoardFileName;
    /** How many cycle will be processed*/
    unsigned int lastCycle ;
    /** Width of the board*/
    unsigned int width;
    /** Height of the board*/
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
