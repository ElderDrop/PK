#include <stdlib.h>
#include "Ant.h"
#include <stdio.h>

void antGame(struct AntProperties *pProperties) {
    unsigned int** board = makeBoard(pProperties);
    if(!board)
        return;
    struct Ant ant;
    putAnt(&ant,board,pProperties);
    for(int i = 0; i < pProperties->moves;i++)
    {
        move(&ant,*pProperties);
        changeDirection(&ant,board);
        changeField(ant,board);
    }
    save(ant, board, pProperties);
}


void changeField(struct Ant ant, unsigned int **board) {
    if(board[ant.y][ant.x] == 0)
        board[ant.y][ant.x] = 1;
    else
        board[ant.y][ant.x] = 0;
}

void move(struct Ant *ant, struct AntProperties properties) {
    switch (ant->direction)
    {
        case UP:
            if (ant->y == 0)
                ant->y = properties.height - 1;
            else
                ant->y--;
            break;
        case RIGHT:
            if (ant->x == (properties.width - 1))
                ant->x = 0;
            else
                ant->x++;
            break;
        case DOWN:
            if(ant->y == (properties.height - 1))
                ant->y = 0;
            else
                ant->y++;
            break;
        case LEFT:
            if(ant->x == 0)
                ant->x = properties.width - 1;
            else
                ant->x--;
            break;
    }

}

void changeDirection(struct Ant *ant, unsigned int** board) {
    switch (ant->direction)
    {
        case UP:
            if(board[ant->y][ant->x] == 0)
                ant->direction = RIGHT;
            else
                ant->direction = LEFT;
            break;
        case RIGHT:
            if(board[ant->y][ant->x] == 0)
                ant->direction = DOWN;
            else
                ant->direction = UP;
            break;
        case DOWN:
            if(board[ant->y][ant->x] == 0)
                ant->direction = LEFT;
            else
                ant->direction = RIGHT;
            break;
        case LEFT:
            if(board[ant->y][ant->x] == 0)
                ant->direction = UP;
            else
                ant->direction = DOWN;
            break;
    }
}

void putAnt(struct Ant *pAnt, unsigned int **board, struct AntProperties *pProperties) {
    pAnt->x = pProperties->startX;
    pAnt->y = pProperties->startY;
    pAnt->direction = UP;
    board[pAnt->y][pAnt->x] = 1;
}

unsigned int **makeBoard(struct AntProperties *pProperties) {
    unsigned int ** board = malloc(pProperties->height * sizeof(unsigned int*));
    for(int i = 0;i <pProperties->height;i++)
    {
        board[i] = malloc(pProperties->width * sizeof(unsigned int));
        for(int j = 0; j < pProperties->width;j++)
            board[i][j] = 0;
    }
    return board;
}

void save(struct Ant ant, unsigned int **board, struct AntProperties *pProperties) {
    FILE* file = fopen(pProperties->outputFileName,"w+");
    board[ant.y][ant.x] = 3;
    for(int i = 0; i < pProperties->height;i++)
    {
        for(int j = 0; j < pProperties->width;j++)
        {
            if(board[i][j] == 1)
                fprintf(file, "1");
            else if(board[i][j] == 0)
                fprintf(file, "0");
            else if(board[i][j] == 3)
                fprintf(file, "3");
        }
        fprintf(file,"\n");
    }
    fclose(file);

}
