#include<stdio.h>
int main()
{
    int A,B,C;
	printf("Digite um valor: ");
	scanf("%d", &A);
	printf("Digite outro valor: ");
	scanf("%d", &B);
	printf("Digite mais um valor: ");
	scanf("%d", &C);
	if(A<B+C && B<A+C && C<A+B)
	{
		if(A == B && B == C)
		{
			printf("Os valores digitados formam um triângulo equilátero.\n");
		}
		else if(A == B && B!=C)
		{
			printf("Os valores digitados formam um triângulo isósceles.\n");
		}
		else
		{
			printf("Os valores digitados formam um triângulo escaleno.\n");
		}
	}
	else
	{
		printf("Os valores digitados não formam um triângulo.\n");
	}
    return 0;
}