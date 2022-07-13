#include<stdio.h>
int main(){


    int horas, minutos;
    printf("Conversao de horas para minutos\nDigite as horas: ");
    scanf("%d",&horas);
    minutos = horas * 60;
    printf("%d horas = %d minutos",horas,minutos);
    return 0;
}