/** @file  */
#ifndef PROJEKT_ANTPROPERTIES_H
#define PROJEKT_ANTPROPERTIES_H

#include <stdbool.h>
/** Contains data for ant game*/
struct AntProperties
{
    /** Width of the board*/
    unsigned int width;
    /** Height of the board*/
    unsigned int height;
    /** Start x position*/
    unsigned int startX;
    /** Start y position*/
    unsigned int startY;
    /** How many moves will be processed*/
    unsigned int moves;
    /** Output file name*/
    char* outputFileName;
};
/**
 * Gets properties from command line
 * @param argc      - quantity of arguments
 * @param argv      - arguments list
 * @param properties - properties to return
 * @return true - if success
 *         false - if failed
 */
bool getAntArguments(int argc, char **argv,struct AntProperties* properties);


bool isValid(struct AntProperties *pProperties);
#endif //PROJEKT_ANTPROPERTIES_H
