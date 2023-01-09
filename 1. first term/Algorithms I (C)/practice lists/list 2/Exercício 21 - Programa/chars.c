#include <stdio.h>
#include <string.h>
int main()
{
    char caractere[10];
    int i, contador = 1, codigo = 32, controle = 0;
    for(i = 0; i<=95;i++)
    {
        caractere[controle] = codigo;
        codigo++;
        controle++;
        if(contador == 10)
        {
            printf("\n");
            printf("%s", caractere);
            controle = 0;
            contador = 0;
            memset(caractere,0, sizeof(caractere));
        }
        if(codigo==127)
        {
            printf("\n");
            printf("%s", caractere);
        }
        contador++;

    }
    return 0;
}