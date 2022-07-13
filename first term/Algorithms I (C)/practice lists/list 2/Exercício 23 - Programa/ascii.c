#include <stdio.h>
int main()
{
    char primeiroChar, segundoChar;
    //int primeiro, segundo;
    printf("Digite o primeiro caractere: ");
    scanf("%c",&primeiroChar);
    getchar();
    printf("Digite o segundo caractere: ");
    scanf("%c",&segundoChar);
    //primeiro = primeiroChar;
    //segundo = segundoChar;
    if(primeiroChar>segundoChar)
    {
        printf("O primeiro vem DEPOIS do segundo na tabela ASCII!");
    }
    else
    {
        printf("O primeiro vem ANTES do segundo na tabela ASCII!");
    }
    return 0;
}
    