#include "GameOfLife.h"
#include "ThreadArg.h"

void gameOfLife(struct GameOfLifeArguments* pArguments) {
    // Prepare game
    struct GameOfLife game;
    game.boardState = true;
    // Load board
    if(!loadBoard(&game,pArguments))
        return;
    pthread_t pthread;
    struct ThreadArg threadArg;

    threadArg.width = pArguments->width;
    threadArg.height = pArguments->height;
    threadArg.board = game.board2;
    logLife(game,-1);
    // Run
    pthread_create(&pthread, NULL,&zero, &threadArg);
    for(int i = 0;i<pArguments->lastCycle;i++)
    {
        if(game.boardState)
        {
            pthread_join(pthread, NULL);
            cycle(game.board1,game.board2,pArguments);
            threadArg.board = game.board1;
        }
        else
        {
            pthread_join(pthread, NULL);
            cycle(game.board2,game.board1,pArguments);
            threadArg.board = game.board2;
        }
        pthread_create(&pthread, NULL,&zero, &threadArg);
        logLife(game,i);
        game.boardState = !game.boardState;
    }
    // Save results
    saveGameToFile(game,pArguments);
    // Free memory
    pthread_detach(pthread);
    clear(&game);
}

// Zero board
void zero(void * pArgs) {
    struct ThreadArg *threadArg = (struct ThreadArg *) pArgs;
    for (int i = 0;i < threadArg->height; i++)
        for(int j = 0;j < threadArg->width;j++)
            threadArg->board[i][j] = '0';
}


void cycle(char **pMain, char **pTo, struct GameOfLifeArguments *pArguments) {
    for(int i = 0; i <pArguments->height; i++)
        for(int j = 0; j< pArguments->width;j++)
        {
            if(pMain[i][j] == '0'  && (countNeighbours(pMain,i,j,pArguments) == 3))
                pTo[i][j] = '1';

            else if(pMain[i][j] == '1' && ((countNeighbours(pMain, i, j,pArguments) == 3) || (countNeighbours(pMain,i, j,pArguments) == 2)))
            {
                pTo[i][j] = '1';
            }
            else {
                pTo[i][j] = '0';
            }
        }

}

int validBoundaries(int x, int y, struct GameOfLifeArguments *pArguments) {
    if(x >= pArguments->width || x < 0 || y >= pArguments->height || y < 0) return 0;
    else return 1;
}

int countNeighbours(char** board,int x, int y, struct GameOfLifeArguments *pArguments){
    int counter = 0;
    if(validBoundaries(x-1,y-1,pArguments)) counter+= isAlive(board[x-1][y-1]);
    if(validBoundaries(x-1,y,pArguments)) counter+= isAlive(board[x-1][y]);
    if(validBoundaries(x-1,y+1,pArguments)) counter+= isAlive(board[x-1][y+1]);
    if(validBoundaries(x,y-1,pArguments)) counter+= isAlive(board[x][y-1]);
    if(validBoundaries(x,y+1,pArguments)) counter+= isAlive(board[x][y+1]);
    if(validBoundaries(x+1,y-1,pArguments)) counter+= isAlive(board[x+1][y-1]);
    if(validBoundaries(x+1,y,pArguments))   counter+= isAlive(board[x+1][y]);
    if(validBoundaries(x+1,y+1,pArguments)) counter+= isAlive(board[x+1][y+1]);

    return counter;
}

int isAlive(char i) {
    if(i == '1') return 1;
    return 0;
}


bool loadBoard(struct GameOfLife *pGame, struct GameOfLifeArguments *pArguments) {
    pGame->board1 = malloc(pArguments->height * sizeof(char*));
    pGame->board2 = malloc(pArguments->height * sizeof(char*));

    for (int i = 0;i < pArguments->height; i++)
    {
        pGame->board1[i] = malloc(pArguments->width * sizeof(char));
        pGame->board2[i] = malloc(pArguments->width * sizeof(char));
        for(int j = 0;j < pArguments->width;j++)
        {
            pGame->board1[i][j] = '0';
            pGame->board2[i][j] = '0';
        }
    }

    pGame->width = pArguments->width;
    pGame->height = pArguments->height;

    FILE *file = fopen(pArguments->startBoardFileName,"r");
    if(file == NULL)
        return false;
    char buffer[pArguments->width+1];
    int k = 0;
    int z = 1;
    while(fgets(buffer,sizeof(buffer),file) != NULL)
    {
        if(z % 2 != 0)
        {
            for (int i = 0; i < pArguments->width; i++)
            {
                if (buffer[i] == '1')
                    pGame->board1[k][i] = '1';
            }
            k++;
        }
        z++;
    }
    fclose(file);
    return true;
}

void saveGameToFile(struct GameOfLife game, struct GameOfLifeArguments *pArguments) {

    FILE* file = fopen(pArguments->endBoardFileName,"w+");
    writeGame(file,game);
    fclose(file);
}

void writeGame(FILE* file,struct GameOfLife game)
{
    char ** board = game.board2;
    if(game.boardState == false)
    {
        board = game.board1;
    }
    for(int i = 0; i < game.height;i++)
    {
        for(int j = 0; j < game.width;j++)
        {
            if(board[i][j] == '1')
                fprintf(file,"1");
            else if(board[i][j] == '0')
                fprintf(file,"0");
        }
        fprintf(file,"\n");
    }
}

void clear(struct GameOfLife *pGame) {
    for(int i = 0; i < pGame->height;i++)
    {
        free(pGame->board1[i]);
        free(pGame->board2[i]);
    }
    free(pGame->board1);
    free(pGame->board2);
}

void logLife(struct GameOfLife game,int cycle) {
    FILE* file = fopen("log","a+");
    fprintf(file,"Gra w życie cykl: %d \n",++cycle);
    writeGame(file,game);
    fclose(file);
}
