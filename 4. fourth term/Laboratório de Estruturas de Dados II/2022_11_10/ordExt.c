#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
typedef struct arquivo
{
    FILE *f;
    int pos, MAX;
    int *buffer;
} arquivo;
void criaArquivoTeste(char *nome);
void SortExterno(char *nome);
int compara(const void *a, const void *b);
int criaArquivosOrdenados(char *nome);
void salvaArquivo(char *nome, int *V, int tam, int flagLinha);
void merge(char *nome, int K, int T);
int procuraMenor(arquivo *arq, int K, int T, int *menor);
void preencheBuffer(arquivo *arq, int T);
int main()
{
    criaArquivoTeste("dados.txt");
    SortExterno("dados.txt");
    return 0;
}
void criaArquivoTeste(char *nome)
{
    int i;
    FILE *f = fopen(nome, "w");
    srand(time(NULL));
    for (i = 1; i < 990; i++)
        fprintf(f, "%d\n", rand());
    fprintf(f, "%d", rand());
    fclose(f);
}
void SortExterno(char *nome)
{
    char novo[20];
    int K = criaArquivosOrdenados(nome);
    int i, T = N / (K + 1);
    printf("Nro de arquivos:%d\n", K);
    printf("K:%d\n", T);
    merge("dadosOrdenados.txt", K, T);
    printf("Fim!\n");
}
int compara(const void *a, const void *b)
{
    if (*(int *)a == *(int *)b)
        return 0; // iguais
    else if (*(int *)a < *(int *)b)
        return -1; // vem antes
    else
        return 1; // vem depois
}
int criaArquivosOrdenados(char *nome)
{
    int V[N];
    char novo[20];
    int cont = 0, total = 0;
    FILE *f = fopen(nome, "r");
    while (!feof(f))
    {
        fscanf(f, "%d", &V[total]);
        total++;
        if (total == N)
        {
            cont++;
            sprintf(novo, "Temp%d.txt", cont);
            qsort(V, total, sizeof(int), compara);
            salvaArquivo(novo, V, total, 0);
            total = 0;
        }
    }
    // caso o arquivo não tenha n de regisro multiplos de 100
    if (total > 0)
    {
        cont++;
        sprintf(novo, "Temp%d.txt", cont);
        qsort(V, total, sizeof(int), compara);
        salvaArquivo(novo, V, total, 0);
    }
    fclose(f);
    return cont;
}
void salvaArquivo(char *nome, int *V, int tam, int flagLinha)
{
    int i;
    FILE *f = fopen(nome, "a");
    for (i = 0; i < tam - 1; i++)
        fprintf(f, "%d\n", V[i]);
    if (flagLinha == 0)
        fprintf(f, "%d", V[tam - 1]);
    else
        fprintf(f, "%d\n", V[tam - 1]);
    fclose(f);
}
void merge(char *nome, int K, int T)
{
    char novo[20];
    int i;
    int *buffer = (int *)malloc(T * sizeof(int)); // buffer de saida
    struct arquivo *arq;
    arq = (arquivo *)malloc(K * sizeof(arquivo));
    for (i = 0; i < K; i++)
    {
        sprintf(novo, "Temp%d.txt", i + 1);
        arq[i].f = fopen(novo, "r");
        arq[i].MAX = 0;
        arq[i].pos = 0;
        arq[i].buffer = (int *)malloc(T * sizeof(int));
        preencheBuffer(&arq[i], T);
    }
    // enquanto houver arquivos para processar
    int menor, qtdBuffer = 0;
    while (procuraMenor(arq, K, T, &menor) == 1)
    {
        buffer[qtdBuffer] = menor;
        qtdBuffer++;
        if (qtdBuffer == T)
        {
            salvaArquivo(nome, buffer, T, 1);
            qtdBuffer = 0;
        }
    }
    if (qtdBuffer != 0)
        salvaArquivo(nome, buffer, qtdBuffer, 1);
    for (i = 0; i < K; i++)
        free(arq[i].buffer);
    free(arq);
    free(buffer);
}
int procuraMenor(arquivo *arq, int K, int T, int *menor)
{
    int i, idx = -1;
    for (i = 0; i < K; i++)
    {
        if (arq[i].pos < arq[i].MAX)
        {
            if (idx == -1)
                idx = i;
            else
            {
                if (arq[i].buffer[arq[i].pos] <
                    arq[idx].buffer[arq[idx].pos])
                    idx = i;
            }
        }
    }
    if (idx != -1)
    {
        *menor = arq[idx].buffer[arq[idx].pos];
        arq[idx].pos++;
        if (arq[idx].pos == arq[idx].MAX)
            preencheBuffer(&arq[idx], T);
        return 1;
    }
    else
        return 0;
}
void preencheBuffer(arquivo *arq, int T)
{
    int i;
    if (arq->f == NULL)
        return;
    arq->pos = 0;
    arq->MAX = 0;
    for (i = 0; i < T; i++)
    {
        if (!feof(arq->f))
        {
            fscanf(arq->f, "%d", &arq->buffer[arq->MAX]);
            arq->MAX++;
        }
        else
        {
            fclose(arq->f);
            arq->f = NULL;
            break;
        }
    }
}