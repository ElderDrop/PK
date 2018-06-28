/** @file  */
#include "AntProperties.h"
#include <stdlib.h>
#include <string.h>

bool isValid(struct AntProperties *pProperties) {
    if(pProperties->outputFileName == NULL || pProperties->outputFileName[0] == '\0')
        return false;
    if(pProperties->width == 0)
        return false;
    if(pProperties->height == 0)
        return false;
    return true;
}

bool getAntArguments(int argc, char **argv, struct AntProperties *properties) {
    if (argc != 14)
    {
        return false;
    }

    for(int i = 2; i < argc;i++)
    {

        if(strcmp("-o",argv[i]) == 0)
        {
            properties->outputFileName = argv[++i];
        }
        if(strcmp("-x",argv[i]) == 0)
        {
            properties->startX = (unsigned int)atoi(argv[++i]);
        }
        if(strcmp("-y",argv[i]) == 0)
        {
            properties->startY = (unsigned int)atoi(argv[++i]);
        }
        if(strcmp("-c",argv[i]) == 0)
        {
            properties->moves = (unsigned int)atoi(argv[++i]);
        }
        if(strcmp("-w",argv[i]) == 0)
        {
            properties->width = (unsigned int)atoi(argv[++i]);
        }
        if(strcmp("-t",argv[i]) == 0)
        {
            properties->height = (unsigned int)atoi(argv[++i]);
        }
        if(strcmp("-h",argv[i]) == 0)
        {
            return false;
        }
    }
    return isValid(properties);
}
