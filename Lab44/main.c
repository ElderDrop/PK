#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

#define BUFFERSIZE 10
#define CLIENTQUNTITY 6

enum States{
    LISTENING,
    WAINTING,
    CONNECTED,
    FREE,
    BUSY
};
enum Commands{
    CONNECT,
    RECIVE,
    CLOSE
};

struct Command{
    enum Commands command;
};

struct Client{
    int id;
    struct Client* revicer;
    enum States state;
};

struct CycleBuffer{
    unsigned short run;
    unsigned int quantity;
    char* input[BUFFERSIZE];
};

void preapareBuffer(struct CycleBuffer *buffer){
    buffer->quantity = 0;
    buffer->run = 0;
    memset(buffer,0,sizeof(char*)*BUFFERSIZE);
}

void clearBuffer(struct CycleBuffer *buffer, char *inputFileForBuffer){
    int i = buffer->quantity;
    if(buffer->run){
        FILE* file = fopen(inputFileForBuffer,"a");
        if(file)
        {
            for(;i< BUFFERSIZE; ++i)
            {
                fprintf(file,"%s",buffer->input[i]);
                free(buffer->input[i]);
            }
            fclose(file);
        }
        else
            printf("Wystapil blad z plikiem %s\n",inputFileForBuffer);
    }
    FILE* pFILE = fopen(inputFileForBuffer,"a");
    if(pFILE)
    {
        for(i = 0; i <buffer->quantity; ++i)
        {
            fprintf(pFILE,"%s",buffer->input[i]);
            free(buffer->input[i]);
        }
        fclose(pFILE);
    }
    else
        printf("Wystapil blad z plikiem %s\n",inputFileForBuffer);
    
    free(buffer);
}


void addToBuffer(char *input, struct CycleBuffer *buffer, char *outputBufferFileName){
    if(buffer->run)
    {
        FILE* output = fopen(outputBufferFileName,"a");
        if(output)
        {
            fprintf(output,"%s",buffer->input[buffer->quantity]);
            fclose(output);
        }
        else printf("Wystapil blad z plikiem %s\n",outputBufferFileName);
    }
    if(buffer->input[buffer->quantity] == NULL)
        free(buffer->input[buffer->quantity]);
    
    buffer->input[buffer->quantity] = input;
    printf("%s",buffer->input[buffer->quantity]);
    buffer->quantity++;
    
    if(buffer->quantity == BUFFERSIZE)
    {
        buffer->run = 1;
        buffer->quantity = 0;
    }
}

void wrtieNotify(char *Notif, struct CycleBuffer *buffer, char *outputFileName) {
    addToBuffer(Notif, buffer, outputFileName);
}
void exec(struct Client *sender, struct Client *reciver, struct Command *cmd, char *buffer){
    if(cmd->command == CONNECT){
        if(sender->state == LISTENING){
            if(reciver->state == LISTENING){
                sender->state = WAINTING;
                reciver->state = FREE;
                sprintf(buffer,"Dzwoni do %d - %d\n",sender->id, reciver->id);
                sender->revicer = reciver;
                reciver->revicer = sender;
            }
            else sprintf(buffer,"Zajenty %d - %d\n",sender->id, reciver->id);
        }
    }
    else if(cmd->command == RECIVE)
    {
        if(sender->state == FREE)
        {
            sender->state = BUSY;
            sender->revicer->state = CONNECTED;
            sprintf(buffer,"Polaczony  %d-%d\n",sender->id, reciver->id);

        }
    }
    else if(cmd->command == CLOSE)
    {
        if(sender->state == FREE)
        {
            if(sender->revicer != NULL)
            {
                sprintf(buffer,"Odbiorca odrzucil CONNECTED | %d <-> %d\n",sender->id, reciver->id);
                sender->state = LISTENING;
                sender->revicer->state = LISTENING;
                sender->revicer->revicer = NULL;
                sender->revicer = NULL;
            }
            else {
                sender->state = LISTENING;
            }

        }
        else if(sender->state == WAINTING)
        {
            sprintf(buffer,"Odrzucil pol %d - %d\n",sender->id, sender->revicer->id);
            sender->state = LISTENING;
            sender->revicer->state = LISTENING;
            sender->revicer->revicer = NULL;
            sender->revicer = NULL;
        }
        else if(sender->state == CONNECTED)
        {
            sprintf(buffer,"Rozmowa zakonczona  %d - %d\n",sender->id, reciver->id);
            sender->state = LISTENING;
            sender->revicer->state = LISTENING;
            sender->revicer->revicer = NULL;
            sender->revicer = NULL;
        }
        else if(sender->state == BUSY)
        {
            sprintf(buffer,"Rozmowa zakonczona  %d - %d\n",sender->id, reciver->id);
            sender->state = LISTENING;
            sender->revicer->state = LISTENING;
            sender->revicer->revicer = NULL;
            sender->revicer = NULL;
        }
    }
}

void randCMD(struct Client **clients, struct Client **sender, struct Client **reciver, struct Command *cmd){
    int senderId, reciverId;
    senderId = rand() % CLIENTQUNTITY;
    *sender = &((*clients)[senderId]);
    if((*sender)->state == LISTENING){
        /* proba polaczenia */
        cmd->command = CONNECT;
        reciverId = rand() % CLIENTQUNTITY;
        while(senderId == reciverId)reciverId = rand() % CLIENTQUNTITY;
        *reciver = &((*clients)[reciverId]);
    }
    else if((*sender)->state == FREE){
        int taken = rand() %1000;
        if(taken > 500) // Odrzucenie połączenia
        {
            cmd->command = CLOSE;
            *reciver = (*sender)->revicer;
        }
        else {
            cmd->command = RECIVE;
            *reciver = (*sender)->revicer;
        }
    }
    else { // koniec polaczenia
        cmd->command = CLOSE;
        *reciver = (*sender)->revicer;
    }
}
static volatile int isWorking = 1;
void work(int e){
    isWorking = 0;
}
int main(int argc, char** argv){
    if(argc > 1){

        srand(time(NULL));
        struct Client *clients = malloc(sizeof(struct Client)*CLIENTQUNTITY);
        struct CycleBuffer* cycleBuffer = malloc(sizeof(struct CycleBuffer));
        preapareBuffer(cycleBuffer);
        char* buffer = malloc(sizeof(char)*128);
        sprintf(buffer,"START\n");
        wrtieNotify(buffer, cycleBuffer, argv[1]);
        int i;
        for(i = 0; i < CLIENTQUNTITY; ++i)
        {
            clients[i].id = i;
            clients[i].revicer = NULL;
            clients[i].state = LISTENING;
        }
        struct Client *sender, *reciver;
        struct Command cmd;
        signal(SIGINT, work);
        signal(SIGQUIT, work);

        while(isWorking)
        {
            buffer = malloc(sizeof(char)*128);
            randCMD(&clients, &sender, &reciver, &cmd);
            exec(sender, reciver, &cmd, buffer);
            wrtieNotify(buffer, cycleBuffer, argv[1]);
            sleep(1);
        }

        free(clients);

        buffer = malloc(sizeof(char)*128);
        sprintf(buffer,"END\n");

        wrtieNotify(buffer, cycleBuffer, argv[1]);
        clearBuffer(cycleBuffer, argv[1]);
    }
    else
        printf("Logowanie do pliku\n");

    return 0;
}