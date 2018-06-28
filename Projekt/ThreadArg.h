/** @file  */
#ifndef PROJEKT_THREADARG_H
#define PROJEKT_THREADARG_H
/** Contains data for thread*/
struct ThreadArg
{
    /** Contains width of board*/
    unsigned int width;
    /**Contains height of bard*/
    unsigned int height;
    /** Board which will be used in thread*/
    char** board;
};
#endif //PROJEKT_THREADARG_H
