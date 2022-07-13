#include<stdio.h>
int main()
{
    float salarioBruto, valorExtras, extras, salarioLiquido, inss;
    printf("Digite seu Salario Bruto: ");
	scanf("%f",&salarioBruto);
    printf("Digite o valor das horas Extras: ");
	scanf("%f",&valorExtras);
    printf("Quantas horas Extras voce cumpriu?: ");
	scanf("%f",&extras);
	extras = valorExtras*extras;
	inss = (salarioBruto + extras)*0.08;
	salarioLiquido = (salarioBruto + extras)-inss;
	printf("Salario Bruto: R$%.2f\nAcrescimo de Extras: R$%.2f\nDesconto do INSS: R$%.2f\nSalario Liquido:R$%.2f",salarioBruto,extras,inss,salarioLiquido);
    return 0;
}