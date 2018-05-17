#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main()
{
    printf("Podaj swoj kod podczotwy\n");
    char code[] = "44-100";
    scanf("%s",code);
    puts(code);
    if (isdigit(code[2]))
    {
        printf("Zly format");
        system("exit");
    }
    char * pch;
    pch=strchr(code,'-');
    printf("znaleciono '-' na %d pozycji\n", pch-code+1);

    FILE *file = fopen("kody.txt","a+");
    fputs(code,file);
    fclose(file);
    char buffor[50];
    int n = sprintf(buffor,"%s",code);
    char shadowCode[] = "44-100";
    memcpy(shadowCode,code,n+1);
    memset(shadowCode, '*',2);
    memset(shadowCode+3,'*',3);
    puts(shadowCode);

    pch = strstr(code,"-");
    strncpy(pch,"|",1);
    puts(code);
    assert(strcmp(shadowCode,code));

    char funcode[] = "44-100";
    memmove(code,code+3,3);
    printf("tak wyglada twoj kod kiedy przeniesie sie 3 ostatnie cyfry na poczatek %s\n",code);

    char* newStr = strdup(code);
    memset (newStr,'0',6);
    memset(newStr+2,'-',1);
    printf("Wyzerowny kod %s\n",newStr);

    strcat(newStr,funcode);
    printf("Scanlony wyzerowany kod i zwykly: %s\n",newStr);

    int quantity = strspn(newStr,"00")-1;
    printf("00 znalezione na pozycji: %d",quantity);
    return 0;
}