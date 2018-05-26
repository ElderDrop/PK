#ifndef PROJEKT_GAMEOFLIFE_H
#define PROJEKT_GAMEOFLIFE_H

#include <stdbool.h>
#include "gameOfLifeArguments.h"


struct GameOfLife{
    unsigned int width;
    unsigned int height;
    char** board1;
    char** board2;
    bool boardState;
};

void gameOfLife(struct GameOfLifeArguments *pArguments);

bool loadBoard(struct GameOfLife *pGame, struct GameOfLifeArguments *pArguments);

void saveGameToFile(struct GameOfLife game, struct GameOfLifeArguments* pArguments);

void cycle(char **pMain, char **pTo, struct GameOfLifeArguments *pArguments);

int countNeighbours(char** board,int x, int y, struct GameOfLifeArguments *pArguments);

int isAlive(char i);

void zero(void * pArgs);

void clear(struct GameOfLife *pGame);
#endif //PROJEKT_GAMEOFLIFE_H
