#include <stdio.h>
int main()
{   
    struct dados
    {
        float notaprova;
        float notatrabalho;
        float media;
        char nome[50];
    }notas;
    printf("Digite seu nome: ");
    scanf(" %[^\n]s", notas.nome);
    setbuf(stdin, NULL);

    printf("Digite a nota de sua prova: ");
    scanf("%f", &notas.notaprova);

    printf("Digite a nota de seu trabalho: ");
    scanf("%f", &notas.notatrabalho);

    notas.media = (notas.notaprova + notas.notatrabalho)/2;

    printf("Aluno %s,\nSua média é %.2f\n", notas. nome, notas.media);

    return 0;
}