//MP6 -30/07/2021 - LATP1 - Vitor Rozeno
#include <stdio.h>
#include <math.h>

int main()
{
	double inicio,fim,erromax,meio;
	printf("\nSolução da equação sen(x) - cos(x) = 0\n");
	printf("\nDigite o início do intervalo que contém a raiz: ");
	scanf("%lf",&inicio);

	printf("\nDigite o fim do intervalo que contém a raiz: ");
	scanf("%lf",&fim);

	printf("\nDigite o erro máximo aceitável: ");
	scanf("%lf",&erromax);

	if(((sin(inicio)-cos(inicio))*(sin(fim)-cos(fim)))<0)
	{
		while((fim-inicio)>erromax)
		{
			meio=(inicio+fim)/2.0;
			if(((sin(inicio)-cos(inicio))*(sin(meio)-cos(meio)))<0)
				fim=meio;
			else
				inicio=meio;
		}
		printf("\nSolução: %.10f\n\n",meio);
	}
	else
		printf("\nO intervalo digitado não contém solução\n\n");
	return 0;
}
