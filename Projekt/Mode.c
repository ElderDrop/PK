/** @file  */
#include "Mode.h"

/**
 * Help
 */
void help()
{
    printf("Pomoc: \n");
    printf("Wybierz tryb gry poprzez -g dla gry w zycie lub -m dla mrowki(Zawsze jako pierwszy argument)\n");
    printf("-h wyswietlenie tego komunikatu\n");
    printf("Gra w zycie wymaga 5 argumentow plus argument wybory gry na poczatku !!: \n");
    printf("-i plik wejsciowy\n");
    printf("-o plik wyjsciowy\n");
    printf("-c liczba cykli do przetworzenia w grze\n");
    printf("-w szerokosc planszy\n");
    printf("-t wyskosc planszy\n");
    printf("PRZYKLADOWE UZYCIE:\n");
    printf("-g -i input -o output -c 100 -w 10 -t 10\n");
    printf("Mrowka Langtona wymaga 6 argumentow plus argument wybory gry na poczatku !!: \n");
    printf("-o plik wyjsciowy\n");
    printf("-c liczba cykli do przetworzenia w grze\n");
    printf("-w szerokosc planszy\n");
    printf("-t wyskosc planszy\n");
    printf("-x koordynat poczatkowy x\n");
    printf("-y koordynat poczatkowy y\n");
    printf("PRZYKLADOWE UZYCIE:\n");
    printf("-m -o outputAnt -x 3 -y 3 -c 50 -w 6 -t 6\n");
}

/**
 *
 * @param argument
 * @return 0 - error mode
 *         1 - game in life
 *         2 - ant game
 */
unsigned int mode(const char *argument) {
    if(strcmp("-g",argument) == 0)
        return 1;
    if(strcmp("-m",argument) == 0)
        return 2;
    return 0;
}
