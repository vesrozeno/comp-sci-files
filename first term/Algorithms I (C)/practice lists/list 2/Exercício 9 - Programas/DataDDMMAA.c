#include<stdio.h>
int main()
{
    int data, dia, mes, ano;
    printf("Digite uma data (DDMMAA): ");
    scanf("%d", &data);
    dia = data/10000;
    mes = (data%10000)/100;
    ano = data%100;
    printf("Dia:%d\nMes:%d\nAno:%d\n",dia, mes, ano);
    return 0;
}
