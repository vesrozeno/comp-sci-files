#include<stdio.h>
int main()
{
    int num;
	printf("Digite um valor inteiro divisível por 4: ");
	scanf("%d", &num);
	if(num%4 == 0)
	{
		printf("Certo. O número %d é divisível por 4!\n", num);
	}
	else
	{
		printf("Número inválido! Não é divisível por 4!\n");
	}
    return 0;
}