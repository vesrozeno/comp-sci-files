//Vitor Rozeno - Mini Prova 03 - 09/07/2021
#include <stdio.h>
int main()
{
    int num1, num2;
    float media;

    printf("Digite dois valores inteiros positivos:");
    do
    {
        printf("\nValor 1: ");
        scanf("%d", &num1);
        printf("\nValor 2: ");
        scanf("%d", &num2);
        if(num1 < 0 || num2 < 0)
        {
            printf("\n\nValores inválidos. Tente novamente . . .\n\n");
        }
    } while (num1 < 0 || num2 < 0);
    media = (num1 + num2) / 2.0;
    if (num1 > num2 || num1 == num2)
    {
        printf("\nMaior valor: %d\nMenor valor: %d\nMédia dos valores: %.2f\n", num1, num2, media);
    }
    else
    {
        printf("\nMaior valor: %d\nMenor valor: %d\nMédia dos valores: %.2f\n", num2, num1, media);
    }
    return 0;
}