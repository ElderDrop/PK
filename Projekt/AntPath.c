/** @file  */
#include "AntPath.h"

void addPath(struct AntPath** pHead, int x, int y, int cycle) {
    if((*pHead) == NULL)
    {
        (*pHead) = malloc(sizeof(struct AntPath));
        init((*pHead),x,y,cycle);
        return;
    }

    struct AntPath* pElement = pHead;
    while(pElement->pNext)
    {
        pElement = pElement->pNext;
    }
    struct AntPath* pNew = malloc(sizeof(struct AntPath));
    init(pNew,x,y,cycle);
    pElement->pNext = pNew;
}

void init(struct AntPath *pElement, int x, int y, int cycle) {
    pElement->x = x;
    pElement->y = y;
    pElement->cycle = ++cycle;
    pElement->pNext = NULL;
}

void printPath(struct AntPath *pHead) {
    struct AntPath* pElement = pHead;
    while(pElement)
    {
        printf("x: %d , y: %d, cykl: %d \n",
               pElement->x,pElement->y,pElement->cycle);
        pElement = pElement->pNext;
    }
}

void clearPath(struct AntPath *pHead) {
    while(pHead)
    {
        struct AntPath* pElement = pHead;
        pHead = pHead->pNext;
        free(pElement);
    }
}


