#include <stdio.h>
int main()
{   
    struct dados
    {
        float notaprova;
        float notatrabalho;
        float media;
        char nome[50];
    }notas[10];
    for (int i = 0; i<10; i++ )
    {

        printf("Digite seu nome: ");
        scanf(" %[^\n]s", notas[i].nome);
        setbuf(stdin, NULL);

        printf("Digite a nota de sua prova: ");
        scanf("%f", &notas[i].notaprova);
        setbuf(stdin, NULL);


        printf("Digite a nota de seu trabalho: ");
        scanf("%f", &notas[i].notatrabalho);
        setbuf(stdin, NULL);


        notas[i].media = (notas[i].notaprova + notas[i].notatrabalho)/2;

        printf("Aluno %s,\nSua média é %.2f\n", notas[i].nome, notas[i].media);
    }
    return 0;
}