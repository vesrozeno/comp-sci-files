#include<stdio.h>
int main()
{
    float salarioAtual, aumento, salarioFinal;
    printf("Digite seu salario atual: ");
	scanf("%f",&salarioAtual);
    printf("Digite a porcentagem de aumento que ira receber: ");
	scanf("%f",&aumento);
	aumento = (aumento/100)*salarioAtual;
	salarioFinal = salarioAtual + aumento;
	printf("Aumento:R$%.2f\nNovo Salario:R$%.2f",aumento, salarioFinal);
    return 0;
}