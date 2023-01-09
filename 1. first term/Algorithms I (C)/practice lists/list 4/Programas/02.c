#include<stdio.h>
int main()
{

    char aposent, controle;
    float consumo, valor, desconto, valorDesconto;
    do{
        printf("Digite os kWh consumidos: ");
        scanf("%f", &consumo);
        getchar();
        printf("Você é aposentado?(S/N)");
        scanf("%c", &aposent);
        valor = consumo * 0.10;
        desconto = valor * 0.15;
        valorDesconto = valor - desconto;
        switch (aposent)
        {
            case 's':case 'S': 
                printf("\nDesconto recebido: R$%.2f\nValor a ser pago(com desconto): R$%.2f\n",desconto, valorDesconto);
                break;
            default: 
                printf("\nValor a ser pago: R$%.2f\n",valor);
                break;
        }
        printf("Prosseguir para próxima residência? (S/N)");
        getchar();
        scanf("%c", &controle);
    }while(controle=='s'||controle=='S');
    return 0;
}