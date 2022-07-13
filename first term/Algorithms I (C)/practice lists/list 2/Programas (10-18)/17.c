#include<stdio.h>
int main()
{
    
    float quilowatts, valor;
    printf("Quilowatts consumidos: ");
	scanf("%f",&quilowatts);
	valor = (quilowatts * 0.12)*1.18;
	printf("Total a ser pago: R$%.2f", valor);
    return 0;
}