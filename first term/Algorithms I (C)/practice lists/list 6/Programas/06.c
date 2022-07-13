#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int matA[4][4], matB[4][4], matC[4][4], i, j, busca;
    srand(time(NULL));
    for(i = 0; i<4; i++)
    {
        for(j = 0; j<4; j++)
        {
            matA[i][j] = rand()%100;
            printf("%d\t", matA[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for(i = 0; i<4; i++)
    {
        for(j = 0; j<4; j++)
        {
            matB[i][j] = rand()%100;
            printf("%d\t", matB[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for(i = 0; i<4; i++)
    {
        for(j = 0; j<4; j++)
        {
            if(matA[i][j]>matB[i][j])
            {
                matC[i][j] = matA[i][j];
            }
            else
            {
                matC[i][j] = matB[i][j];
            }
            printf("%d\t", matC[i][j]);
        }
        printf("\n");
    }

    return 0;
}