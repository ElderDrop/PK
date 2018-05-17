#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void sortuj(int* tab, int rozmiarTablicy){
    int i = 0;
    int j = --rozmiarTablicy;
    while(j)
    {
        i = 0;
        while(i < j){
            if(tab[i] > tab[i+1]){
                int tmp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = tmp;
            }
            ++i;
        }
        --j;
    }

}
void showResults(int argc,char **argv,double *avg,double* median,int* min,int* max)
{
    int column = 0;
    while (column < argc - 2) {
        printf("%s\nSrednia: %f\nMediana: %f\nWartosc minimalna: %d\nWartoscMaksymalna: %d\n\n",
               argv[column + 2], avg[column], median[column], min[column], max[column]);
        column++;
    }
}

int main() {
    //Pobranie argumentow
    int argc = 0;
    char **argv;
    int argLength;
    FILE *binFile = fopen("propertis.dat", "r");
    if (binFile != NULL) {
        fread((void *) &argc, sizeof(int), 1, binFile);
        argv = calloc(argc, sizeof(char *));
        int i = 0;
        while (i < argc) {
            fread((void *) &argLength, sizeof(int), 1, binFile);
            argv[i] = calloc(argLength, sizeof(char));
            fread((void *) argv[i], sizeof(char), argLength, binFile);
            i++;
        }
        fclose(binFile);
    }
    //Przygotowanie pamieci
    int i = 0;
    int messQunatity = atoi(argv[0]);
    double *avg = calloc(messQunatity - 2, sizeof(double));
    memset(avg, 0, (messQunatity - 2) * sizeof(double));
    int *min = calloc(messQunatity - 2, sizeof(int));
    memset(min, INT_MAX, (messQunatity - 2) * sizeof(int));
    int *max = calloc(messQunatity - 2, sizeof(int));
    memset(max, INT_MIN, (messQunatity - 2) * sizeof(int));
    double *median = calloc(messQunatity - 2, sizeof(double));
    int **results = calloc(argc - 2, sizeof(int *));
    while (i < argc - 2) {
        results[i] = calloc(messQunatity, sizeof(int));
        i++;
    }
    //Operacje na plikui
    FILE *csv = fopen(argv[1], "r");
    if (csv != NULL) {
        i = 0;
        int column;
        while (i < messQunatity) {
            column = 0;
            while (column < argc - 2) {
                fscanf(csv, "%d%*[;]", results[column] + i);
                avg[column] += *(results[column] + i);
                if (min[column] > *(results[column] + i)) min[column] = *(results[column] + i);
                if (max[column] < *(results[column] + i)) max[column] = *(results[column] + i);
                column++;
            }
            i++;
        }
        fclose(csv);
        column = 0;
        while (column < argc - 2) {
            avg[column] = avg[column] / messQunatity;
            column++;
        }
        column = 0;
        if (messQunatity % 2) {
            while (column < argc - 2) {
                sortuj(results[column], messQunatity);
                median[column] = results[column][messQunatity / 2];
                column++;
            }
        } else {
            while (column < argc - 2) {
                sortuj(results[column], messQunatity);
                median[column] =
                        (results[column][messQunatity / 2] + results[column][(messQunatity / 2) - 1]) / 2;
                column++;
            }
        }
        showResults(argc,argv,avg,median,min,max);
        free(avg);
        free(min);
        free(max);
        free(median);
        i = 0;
        while (i < argc - 2) {
            free(results[i]);
            i++;
        }
        free(results);

    }
    i = 0;
    while (i < argc) {
        free(argv[i]);
        i++;
    }
    free(argv);
    return 0;
}