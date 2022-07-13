#include<stdio.h>
int main()
{
	float salario, salarioReajuste;
    char controle;
    do{
        printf("Digite seu salário: ");
        scanf("%f", &salario);
        if(salario<500)
        {
            salarioReajuste = salario * 1.15;
            printf("Salário com Reajuste:R$ %.2f\n",salarioReajuste);
        }
        else if(salario<=1000)
        {
            salarioReajuste = salario * 1.1;
            printf("Salário com Reajuste:R$ %.2f\n",salarioReajuste);
        }
        else
        {
            salarioReajuste = salario * 1.05;
            printf("Salário com Reajuste:R$ %.2f\n",salarioReajuste);
        }
        printf("Prosseguir para o próximo funcionário? (S/N)");
        getchar();
        scanf("%c", &controle);
    }while(controle == 'S'|| controle == 's');
        
    return 0;
}