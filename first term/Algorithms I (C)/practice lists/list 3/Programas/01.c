#include<stdio.h>
int main()
{
    float num;
	printf("Digite um número: ");
	scanf("%f", &num);
	if (num>=20 && num<=100)
	{
		printf("O número %.2f está no intervalo de 20 a 100.\n", num);
    }
	else
    {
		printf("O número %.2f não está no intervalo de 20 a 100.\n", num);
    }
    return 0;
}