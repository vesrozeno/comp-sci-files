//Vitor Rozeno - Mini Prova 02 - 02/07/2021
#include <stdio.h>
int main()
{
    char carac, caracMod;
    printf("Digite um caractere: ");
    scanf("%c", &carac);
    if(carac>=65&&carac<=90)
    {
        caracMod = carac + 32;
        printf("Transformando de letra maiúscula para minúscula:\n%c ---> %c\n", carac, caracMod);
    }
    else if(carac>=97&&carac<=122)
    {
        caracMod = carac - 32;
        printf("Transformando de letra minúscula para maiúscula:\n%c ---> %c\n", carac, caracMod);
    }
    else
    {
        printf("Caractere digitado: %c\n", carac);
    }

    return 0;
}

