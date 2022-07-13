#include <stdio.h>
int main()
{
    char caractere[95];
    int i, codigo = 32;
    for(i = 0; i<=95;i++)
    {
        if(codigo%2 == 1 && codigo <=127)
        {
            caractere[i] = codigo;
            printf("\n");
            printf("%c", caractere[i]);
            
        }
        codigo++;
    }
    return 0;
}