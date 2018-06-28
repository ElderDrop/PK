/** @file  */
#ifndef PROJEKT_GAMEOFLIFE_H
#define PROJEKT_GAMEOFLIFE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "GameOfLifeArguments.h"

/** Contains all data for the simulation */
struct GameOfLife {
    /** Width of the board*/
    unsigned int width;
    /** Height of the board*/
    unsigned int height;
    /** First board */
    char** board1;
    /** Second board */
    char** board2;
    /** Which of the board is now main */
    bool boardState;
};

/**
 * Main function which maneges as ant game
 * @param pProperties - properties instance
 */
void gameOfLife(struct GameOfLifeArguments *pArguments);

/**
 * Creates board from file
 * @param pGame      - game instance
 * @param pArguments - arguments pointer
 * @return true  - if success
 *         false - if failed
 */
bool loadBoard(struct GameOfLife *pGame, struct GameOfLifeArguments *pArguments);

/**
 * Saves game state to file
 * @param pGame      - game instance
 * @param pArguments - arguments pointer
 */
void saveGameToFile(struct GameOfLife game, struct GameOfLifeArguments* pArguments);

/**
 * Do one cycle of the game
 * @param pMain         - pointer of original board
 * @param pTo           - pointer of changed board
 * @param pArguments    - arguments pointer
 */
void cycle(char **pMain, char **pTo, struct GameOfLifeArguments *pArguments);

/**
 * Count neighbours
 * @param board     - board
 * @param x         - coordinates x
 * @param y         - coordinates y
 * @param pArguments- arguments pointer
 * @return quantity of neighbours
 */
int countNeighbours(char** board,int x, int y, struct GameOfLifeArguments *pArguments);

/**
 * Check if cell is alive
 * @param  i - value on board
 * @return 1 - if alive
 *         0 - if dead
 */
int isAlive(char i);

/**
 * Check if point is in valid boundaries
 * @param board     - board
 * @param x         - coordinates x
 * @param y         - coordinates y
 * @param pArguments- arguments pointer
 * @return 0 - if is in boundaries
 *         1 - if is not in boundaries
 */
int validBoundaries(int x, int y, struct GameOfLifeArguments* pArguments);

/**
 * Puts zero in every cell in table
 * @param pArgs - arguments passed to thread pointer
 */
void zero(void* pArgs);

/**
 * Write game state to file
 * @param file - file where content will be put
 * @param game - game instance
 */
void writeGame(FILE* file,struct GameOfLife game);

/**
 * Logs game state to file
 * @param game  - game instance
 * @param cycle - cycle of game -1
 */
void logLife(struct GameOfLife game,int cycle);

/**
 * Frees memory
 * @param pGame - game state pointer
 */
void clear(struct GameOfLife *pGame);
#endif //PROJEKT_GAMEOFLIFE_H
