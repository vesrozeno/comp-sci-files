#include<stdio.h>
int main()
{
    int num, inc;
    num = 0;
    for(inc = 0; inc<=500; inc+=2)
    {
        num = inc+num;
    }
    printf("Soma dos pares de 0 a 500: %d\n", num);
    return 0;
}