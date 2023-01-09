#include<stdio.h>
#define MAX 4
int main()
{
    char respostas[5][10], gabarito[10], i, j;
    int resultado[10];
    for(i = 0; i<5; i++)
    {
        printf("Respostas do aluno %d:", i+1);
        for(j = 0; j< MAX ; j++)
        {
            printf("\n");
            do
            {
                scanf("%c", &respostas[i][j]);
            } while (respostas[i][j]<65||respostas[i][j]>68&&respostas[i][j]<97||respostas[i][j]>100);
        }
        printf("\n");
    }
    printf("Gabarito: ");
    for(i = 0; i<MAX; i++)
    {
        printf("\n");
        do
            {
                scanf("%c", &gabarito[i]);
            } while (gabarito[i]<65||gabarito[i]>68&&gabarito[i]<97||gabarito[i]>100);
    }
    printf("\nGabarito: ");
    for(i = 0; i<MAX; i++)
    {
        printf("%c\t",gabarito[i]);
    }
    printf("\n\n");
    for(i = 0; i<5; i++)
    {
        printf("Respostas do aluno %d:\t", i+1);
        for(j = 0; j< MAX ; j++)
        {
            printf("%c\t", respostas[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("Resultado:\t");
    for(i = 0; i<5; i++)
    {
        for(j = 0; j< MAX ; j++)
        {
            if(respostas[i][j] == gabarito[j])
            resultado[i]++;
        }
        printf("\n\nResultado do aluno %d: %d acertos\n", i+1, resultado[i]);
    }
    printf("\n");

    return 0;
}