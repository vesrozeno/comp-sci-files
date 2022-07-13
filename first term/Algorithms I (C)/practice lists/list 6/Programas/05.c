#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int mat[5][5], i, j, busca;
    srand(time(NULL));
    for(i = 0; i<5; i++)
    {
        for(j = 0; j<5; j++)
        {
            mat[i][j] = rand()%100;
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\nBuscar número: ");
    scanf("%d", &busca);
    for(i = 0; i<5; i++)
    {
        for(j = 0; j<5; j++)
        {
            if(mat[i][j] == busca)
            {
                printf("Número %d:\ni = %d\nj = %d", busca, i+1, j+1);
            }
        }
    }
    if(mat[5][5]!= busca)
    {
        printf("Número não encontrado!!\n\n");
    }

    return 0;
}