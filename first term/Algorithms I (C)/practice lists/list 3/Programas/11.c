#include<stdio.h>
int main()
{
	float consumo, valor;
	printf("Digite o seu consumo em kW/h: ");
	scanf("%f", &consumo);
	if(consumo<=50)
	{
		valor = consumo * 1.0;
		printf("Valor a ser pago:R$%.2f\n", valor);
	}
	else if(consumo<=100)
	{
		valor = 50*1 +(consumo - 50.0)*1.3;
		printf("Valor a ser pago:R$%.2f\n", valor);
	}
	else if(consumo<=150)
	{
		valor = 50*1 + 50*1.3 + (consumo - 100.0)*1.6;
		printf("Valor a ser pago:R$%.2f\n", valor);
	}
	else
	{
		valor = 50*1 + 50*1.3 + 50*1.6 + (consumo - 150.0)*2;
		printf("Valor a ser pago:R$%.2f\n", valor);
	}
    return 0;
}