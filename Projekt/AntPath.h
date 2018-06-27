#ifndef PROJEKT_ANTPATH_H
#define PROJEKT_ANTPATH_H

#include <stdlib.h>
#include <stdio.h>

struct AntPath {
    int x;
    int y;
    int cycle;
    struct AntPath* pNext;
};

/**
 * Add path at the end of list
 * @param pHead - pointer of pointer on first element of list
 * @param x     - x var of ant
 * @param y     - y var of ant
 * @param cycle - cycle of game -1
 */
void addPath(struct AntPath** pHead,int x,int y,int cycle);

/**
 * Inits data in struct
 * @param pElement - element pointer
 * @param x     - x var of ant
 * @param y     - y var of ant
 * @param cycle - cycle of game -1
 */
void init(struct AntPath* pElement,int x,int y,int cycle);

/**
 * Prints data from the list
 * @param pHead - first element of list pointer
 */
void printPath(struct AntPath* pHead);

/**
 * Frees memory of list
 * @param pHead - first element of list pointer
 */
void clearPath(struct AntPath* pHead);
#endif //PROJEKT_ANTPATH_H
