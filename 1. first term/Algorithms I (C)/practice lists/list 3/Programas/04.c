#include<stdio.h>
int main()
{
	float a, b, c, media;
	printf("Digite um valor a: ");
	scanf("%f", &a);
	printf("Digite um valor b: ");
	scanf("%f", &b);
	printf("Digite um valor c: ");
	scanf("%f", &c);
	media = (a+b+c)/3;
	printf("Média dos valores digitados: %.2f",media);
	if (media > a || media > b || media > c)
	{
		printf("\nA media é maior que um dos valores digitados!\n");
    }
    return 0;
}