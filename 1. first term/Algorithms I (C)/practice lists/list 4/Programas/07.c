#include<stdio.h>
int main()
{
    int num, res, cont;
    printf("Cálculo de Tabuada:\nEscolha um número: ");
    scanf("%d", &num);
    printf("=======Tabuada do %d =======", num);
    for(cont = 0; cont<=10; cont++)
    {
        res = num * cont;
        printf("\n\t%d x %d = %d", num, cont, res);
    }
    printf("\n=========================\n");
    return 0;
}