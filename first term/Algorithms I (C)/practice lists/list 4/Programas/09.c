#include<stdio.h>
int main()
{
    int ante, pos, cont;
    ante = 1;
    pos = 0;
    for(cont = 1; cont<=15; cont++)
    {
        pos = ante+pos;
        ante = pos - ante;
        printf("\t%d", pos);
    }
    printf("\n");
    return 0;
}