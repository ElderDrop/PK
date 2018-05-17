#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void help()
{
    char* tab = malloc(6*sizeof(char));
    printf("%d",sizeof(&tab));
    printf("generator <ilosc pomiarow> <pliku.csv> <naglowek>  [<naglowek> ...]\n");
}

int main(int argc, char** argv){
    if(argc > 1){
        int i = 1;
        FILE* file = fopen("propertis.dat","wb");
        if(file!= NULL){
            int lettersQuantity;
            argc -= 1;
            fwrite((void*)&argc,sizeof(int),1,file);
            while(i<argc){
                lettersQuantity = strlen(argv[i])+1;
                fwrite((void*)&lettersQuantity,sizeof(int),1,file);
                fwrite((void*)argv[i],sizeof(char),lettersQuantity,file);
                i++;
            }
            fclose(file);
            srand(time(NULL));
            int messQunatity = atoi(argv[1]);
            int headersQuantity = argc -3;
            int tmpWynik;
            if(headersQuantity > 0){
                FILE* plikWyjsciowy = fopen(argv[2],"w");
                while(messQunatity){
                    i = headersQuantity;
                    while(i){
                        tmpWynik = (rand() % 200) - 100;
                        fprintf(plikWyjsciowy,"%d",tmpWynik);
                        if(i > 1) fputs(";",plikWyjsciowy);
                        else if(i == 1)fputs("\n",plikWyjsciowy);
                        i--;
                    }
                    messQunatity--;
                }
                fclose(plikWyjsciowy);
            }
        }
    }
    else{
        help();
    }
    return 0;
}