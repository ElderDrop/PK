#ifndef PROJEKT_ANT_H
#define PROJEKT_ANT_H

#include "AntProperties.h"

enum Directions {UP,RIGHT,DOWN,LEFT};

struct Ant
{
    enum Directions direction;
    unsigned int x;
    unsigned int y;
};

void changeDirection(struct Ant* ant, unsigned int** board);

void move(struct Ant* ant, struct AntProperties properties);

void antGame(struct AntProperties* pProperties);

unsigned int **makeBoard(struct AntProperties *pProperties);

void putAnt(struct Ant *pAnt, unsigned int **pInt, struct AntProperties *pProperties);

void changeField(struct Ant ant, unsigned int **board);

void save(struct Ant ant, unsigned int **board, struct AntProperties *pProperties);
#endif //PROJEKT_ANT_H
