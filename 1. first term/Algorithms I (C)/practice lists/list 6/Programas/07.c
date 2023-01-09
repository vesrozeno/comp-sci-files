#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int mat[4][4];
    srand(time(NULL));
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            mat[i][j] = rand()%21;
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            if(i<j)
            {
                mat[i][j] = 0;
            }
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}