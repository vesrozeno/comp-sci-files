#include<stdio.h>
#define CNH 18
#define APOSENTADO 70
int main()
{
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("\nVoce tem %d anos", idade);
    if(idade>=CNH)
    {
        printf("\nVoce pode dirigir!");
        if(idade>=APOSENTADO)
        {
            printf("\nVoce pode usufruir da aposentadoria!");
        }
    }
    
}