#include<stdio.h>
int main()
{
    char nome[40];
    int idade;

    printf("\nDigite seu nome: ");
    scanf("%s", nome);

    printf("\nDigite sua idade: ");
    scanf("%d",&idade);

    printf("\n%p ", &nome);
    printf("\n%p", &idade);
    printf("\n%lu ", sizeof(nome));
    printf("\n%lu\n", sizeof(idade));

    return 0;
}