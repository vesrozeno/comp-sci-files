#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int dado1, dado2, dado3;
    srand(time(NULL));
    for(int i=0; i<7; i++)
    {   
        dado1 = 1 + rand()%6;
        dado2 = 1 + rand()%6;
        dado3 = 1 + rand()%6;
        printf("\n%d\t%d\t%d\n", dado1, dado2, dado3);
    }
    return 0;
}