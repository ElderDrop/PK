#ifndef PROJEKT_ANT_H
#define PROJEKT_ANT_H

#include "AntProperties.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Directions for ant
 */
enum Directions {UP,RIGHT,DOWN,LEFT};

struct Ant
{
    enum Directions direction;
    unsigned int x;
    unsigned int y;
};

/**
 * Rotate ant
 * @param ant   - ant instance
 * @param board - board instance
 */
void changeDirection(struct Ant* ant, unsigned int** board);

/**
 * Move ant forward
 * @param ant        - ant instance
 * @param properties - properties of the game pointer
 */
void move(struct Ant* ant, struct AntProperties properties);

/**
 * Main function which manages as ant game
 * @param pProperties - arguments pointer
 */
void antGame(struct AntProperties* pProperties);

/**
 * Allocates memory for game board
 * @param pProperties - properties of the game pointer
 * @return pointer of the board
 */
unsigned int **makeBoard(struct AntProperties *pProperties);

/**
 * Puts ant on the board(inits data in ant instance)
 * @param pAnt        - ant pointer
 * @param board       - board
 * @param pProperties - properties of the game pointer
 */
void putAnt(struct Ant *pAnt, unsigned int **board, struct AntProperties *pProperties);

/**
 * Change value on board under ant
 * @param ant   - ant instance
 * @param board - board
 */
void changeField(struct Ant ant, unsigned int **board);

/**
 * Saves game to the file
 * @param ant           - ant instance
 * @param board         - board
 * @param pProperties   - properties of the game pointer
 */
void save(struct Ant ant, unsigned int **board, struct AntProperties *pProperties);

/**
 * Logs game state to file
 * @param ant           - ant instance
 * @param board         - board
 * @param pProperties   - properties of the game pointer
 * @param cycle         - cycle of game -1
 */
void logAnt(struct Ant ant, unsigned int **board, struct AntProperties *pProperties,int cycle);

/**
 * Write game state to file
 * @param file          - file reference
 * @param ant           - ant instance
 * @param board         - board
 * @param pProperties   - properties of the game pointer
 */
void writeAntGameToStream(FILE *file,struct Ant ant, unsigned int **board, struct AntProperties *pProperties);

/**
 * Frees board memory
 * @param board         - board
 * @param pProperties   - properties of the game pointer
 */
void clearBoard(unsigned int **board,struct AntProperties* pProperties);
#endif //PROJEKT_ANT_H
