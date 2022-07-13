#include<stdio.h>
int main()
{
	float num;
	printf("Digite um número: ");
	scanf("%f", &num);
	printf("Valor digitado:%.2f",num);
	if (num>0) 
	{
		printf("\nValor positivo.");
    }
	else if(num==0)
	{
		printf("\nValor nulo.");
    }
	else
    {
		printf("\nValor negativo.");
    }
    return 0;
}