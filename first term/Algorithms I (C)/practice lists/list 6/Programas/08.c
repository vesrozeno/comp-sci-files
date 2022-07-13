#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int mat[5][5], i, j;
    srand(time(NULL));
    printf("Cartela:\n");
    for(i = 0; i<5; i++)
    {
        for(j = 0; j<5; j++)
        {
            if(i==0&&j==0)
            {
                mat[i][j] = rand()%100;   
                printf("%d\t", mat[i][j]);
            }
            else
            {
                do{
                    mat[i][j] = rand()%100;   
                }while(mat[i][j] == mat[i-1][j-1]);
                printf("%d\t", mat[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}