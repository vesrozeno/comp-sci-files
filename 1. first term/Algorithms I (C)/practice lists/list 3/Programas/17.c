#include<stdio.h>
int main()
{
    float peso, altura, imc;
	printf("Digite seu peso: ");
	scanf("%f", &peso);
	printf("Digite sua altura: ");
	scanf("%f", &altura);
	imc = peso / (altura*altura);
    if(imc<18.5)
    {
    	printf("Você está desnutrido.\nIMC = %.2f\n", imc);
    }
    else if(imc>=18.5 && imc<25.0)
    {
    	printf("Você em seu peso normal.\nIMC = %.2f\n", imc);
    }
    else if(imc>=25.0 && imc<30.0)
    {
    	printf("Você está em sobrepeso.\nIMC = %.2f\n", imc);
    }
    else if(imc>=30.0 && imc<40)
    {
    	printf("Você está obeso.\nIMC = %.2f\n", imc);
    }
    else
    {
    	printf("Você está em estado de obesidade mórbida.\nIMC = %.2f\n", imc);
    }
    return 0;
}