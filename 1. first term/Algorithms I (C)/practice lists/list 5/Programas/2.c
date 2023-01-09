#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 1000
int main()
{
    int v[max], soma = 0, nPar=0, nImpar=0, somaPar=0, somaImpar=0;
    float media, mediaPar, mediaImpar;
    srand(time(NULL));
    for(int i = 0; i < max; i++)
    {
        v[i] = rand()%100;
    }
    for(int i = 0; i < max; i++)
    {
        printf("%dº: %d\n", i, v[i]);
        soma += v[i];
        if(v[i]%2 == 0)
        {
            nPar++;
            somaPar += v[i];
        }
        else
        {
            nImpar++;
            somaImpar+=v[i];
        }
    }
    media = soma/max;
    mediaPar = somaPar/nPar;
    mediaImpar = somaImpar/nImpar;

    printf("\nMédia dos números: %.2f", media);
    printf("\nMédia dos números pares: %.2f", mediaPar);
    printf("\nMédia dos números ímpares: %.2f", mediaImpar);
    printf("\nQuantidade de números pares: %.d", nPar);
    printf("\nQuantidade de números ímpares: %.d\n", nImpar);
    return 0;
}