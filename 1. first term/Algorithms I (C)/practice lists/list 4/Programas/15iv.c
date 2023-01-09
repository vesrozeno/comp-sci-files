#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int dado, dado1=0, dado2=0, dado3=0, dado4=0, dado5=0, dado6=0;
    srand(time(NULL));
    for(int i=0; i<6000;i++)
    {
        dado = 1 + rand()%6;
        switch (dado)
        {
        case 1:
            dado1++;
        break;
        case 2:
            dado2++;
        break;
        case 3:
            dado3++;
        break;
        case 4:
            dado4++;
        break;
        case 5:
            dado5++;
        break;
        case 6:
            dado6++;
        break;
        
        }
    }
    printf("Face 1: %d vezes\nFace 2: %d vezes\nFace 3: %d vezes\nFace 4: %d vezes\nFace 5: %d vezes\nFace 6: %d vezes\n", dado1, dado2, dado3, dado4, dado5, dado6);
    return 0;
}