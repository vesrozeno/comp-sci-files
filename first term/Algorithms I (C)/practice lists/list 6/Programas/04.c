#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int mat[4][4], locI, locJ, maior, i, j;
    srand(time(NULL));
    for(i = 0; i<4; i++)
    {
        for(j = 0; j<4; j++)
        {
            mat[i][j] = rand()%100;
            printf("%d\t", mat[i][j]);
            if(i==0 && j == 0)
            {
                locI = i + 1;
                locJ = j + 1;
                maior = mat[i][j];
            }
            else if(mat[i][j]>maior)
            {
                locI = i + 1;
                locJ = j + 1;
                maior = mat[i][j];
            }
        }
        printf("\n");
    }
    printf("\n\nLocalização do maior número:\nMaior número: %d\ni = %d\nj = %d",maior, locI, locJ);
    return 0;
}