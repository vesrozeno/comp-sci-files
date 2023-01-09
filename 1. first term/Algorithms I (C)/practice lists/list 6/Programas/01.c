#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int mat[4][4], contador=0;
    srand(time(NULL));
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            mat[i][j] = rand()%100;
            printf("%d\t", mat[i][j]);
            if(mat[i][j]>10)
            {
                contador++;
            }
        }
        printf("\n");
    }
    printf("\n\n%d números maiores que 10 !!", contador);
    return 0;
}