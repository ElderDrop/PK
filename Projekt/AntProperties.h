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

bool getAntArguments(int argc, char **argv,struct AntProperties* properties);

#endif //PROJEKT_ANTPROPERTIES_H
