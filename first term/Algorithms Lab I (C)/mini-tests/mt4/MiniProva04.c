//Vitor Rozeno - Mini Prova 04 - LATP 1 - Unesp
#include<stdio.h>
int main()
{
    float vetor[10];
    for(int i = 0; i < 10; i++)
    {
        printf("Digite um número: ");
        scanf("%f", &vetor[i]);
    }
    printf("Valores negativos digitados: ");
    for(int i = 0; i < 10; i++)
    {
        if (vetor[i]<0)
        {
            printf("%.2f\t", vetor[i]);
        }
    }
    printf("\n");
    return 0;
}