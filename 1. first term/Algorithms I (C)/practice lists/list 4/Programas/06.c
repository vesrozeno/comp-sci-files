#include <stdio.h>
int main()
{
    int num, fatorial;
    printf("Cálculo de fatorial:\nDigite um número: ");
    scanf("%d", &num);
    for(fatorial = 1; num > 1; num = num-1)
    {
        fatorial = fatorial * num;
    }
    printf("Fatorial: %d\n", fatorial);
    return 0;
}