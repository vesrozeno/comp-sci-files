#include<stdio.h>
int main()
{
    int num1, num2, num3;
	printf("Digite um número inteiro: ");
	scanf("%d", &num1);
	printf("Digite mais um número inteiro: ");
	scanf("%d", &num2);
	printf("Digite mais um número inteiro: ");
	scanf("%d", &num3);
	if(num1<num2 && num2<num3)
	{
		printf("\nOrdem Crescente: %d\t%d\t%d\t\n",num1, num2, num3);
	}
	else if(num1<num3 && num3<num2)
	{
		printf("\nOrdem Crescente: %d\t%d\t%d\t\n",num1, num3, num2);
	}
	else if(num2<num1 && num1<num3)
	{
		printf("\nOrdem Crescente: %d\t%d\t%d\t\n",num2, num1, num3);
	}
	else if(num2<num3 && num3<num1)
	{
		printf("\nOrdem Crescente: %d\t%d\t%d\t\n",num2, num3, num1);
	}
	else if(num3<num2 && num2<num1)
	{
		printf("\nOrdem Crescente: %d\t%d\t%d\t\n",num3, num2, num1);
	}
	else
    {
		printf("\nOrdem Crescente: %d\t%d\t%d\t\n",num3, num1, num2);
	}
    return 0;
}