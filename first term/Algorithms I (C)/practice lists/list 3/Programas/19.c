#include<stdio.h>
int main()
{
    float custo, distancia, consumoMedio, combNec;
    int tipo;
	printf("Qual o tipo de combustível?:\n(1)Gasolina\n(2)Álcool\n(3)Diesel\n");
	scanf("%d", &tipo);
	printf("\nDigite a distância a ser percorrida (km): ");
	scanf("%f", &distancia);
	printf("\nDigite o consumo médio de seu veículo (km/L): ");
	scanf("%f", &consumoMedio);
	combNec = distancia/consumoMedio;
	switch(tipo)
	{ 
		case 1:
			custo = combNec * 4.79;
            printf("Combustível necessário: %.2f L\nCusto: R$%.2f\n", combNec, custo);
            break;
		case 2:
			custo = combNec * 2.68;
            printf("Combustível necessário: %.2f L\nCusto: R$%.2f\n", combNec, custo);
            break;
		case 3:
			custo = combNec * 2.64;
            printf("Combustível necessário: %.2f L\nCusto: R$%.2f\n", combNec, custo);
            break;
		default:
			printf("Digite um tipo válido.\n");
            break;
    }

    return 0;
}