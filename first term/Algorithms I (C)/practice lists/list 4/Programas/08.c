#include<stdio.h>
int main()
{
    int i;
    printf("Números divisíveis por 4 entre 1 e 200:");
    for (i=0;i<=200;i+=4)
    {
        printf("\n%d", i);
    }
    return 0;
}