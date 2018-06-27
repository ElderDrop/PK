#ifndef PROJEKT_ANTPROPERTIES_H
#define PROJEKT_ANTPROPERTIES_H

#include <stdbool.h>

struct AntProperties
{
    unsigned int width;
    unsigned int height;
    unsigned int startX;
    unsigned int startY;
    unsigned int moves;
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
