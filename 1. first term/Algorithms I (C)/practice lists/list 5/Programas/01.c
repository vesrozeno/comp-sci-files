#include<stdio.h>
int main()
{
    int v[10] = {2,6,8,3,10,9,1,21,33,14};
    const int x = 2, y = 4;
    printf("\n\na) %d\n\n", v[x+1]);
    printf("\n\nb) %d\n\n", v[x+2]);
    printf("\n\nc) %d\n\n", v[x+3]);
    printf("\n\nd) %d\n\n", v[y*1]);
    printf("\n\ne) %d\n\n", v[x*3]);
    printf("\n\nf) %d\n\n", v[x*2]);
    printf("\n\ng) %d = ERRO\n\n", v[x*5]);
    printf("\n\nh) %d\n\n", v[v[x+y]]);
    printf("\n\ni) %d\n\n", v[x+y]);
    printf("\n\nj) %d\n\n", v[8 - v[2]]);
    printf("\n\nk) %d = ERRO\n\n", v[v[4]]);
    printf("\n\nl) %d\n\n", v[v[v[7]]]);
    printf("\n\nm) %d = ERRO\n\n", v[v[1]*v[4]]);
    printf("\n\nn) %d\n\n", v[x+4]);
    return 0;
}