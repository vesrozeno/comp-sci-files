// Vitor Emanuel da Silva Rozeno - RA: 211044539
// Projeto 4 - caixasefilas.c
#include <stdio.h>
#include <stdlib.h>
// Structs.
typedef struct structCliente
{
    int idade;
    int inst;
    int tempo;
} Cliente;
typedef struct structFila
{
    int idade;
    int pos;
} Fila;
// Var global.
int nClientes;
// Protótipos.
void leituraDados(Cliente *);
int ordenaInst(const void *, const void *);
int caixaLivre(int *, int, int *, int);
int ocupaCaixa(int *, Cliente *, Fila *, int *, int, int *);
void insereFila(Cliente *, Fila *, int *, int, int *);
void imprimeFila(Fila *, int);
void operacoes(Cliente *, int);
// Função Principal.
int main()
{
    int i, mCaixas;

    // Lê n clientes e m caixas.
    scanf(" %d %d", &nClientes, &mCaixas);

    Cliente listaClientes[nClientes];

    leituraDados(listaClientes);
    operacoes(listaClientes, mCaixas);

    return 0;
}
// Função para Leitura de dados.
void leituraDados(Cliente *vetor)
{
    int i;
    for (i = 0; i < nClientes; i++)
    {
        scanf(" %d %d %d", &vetor[i].idade, &vetor[i].inst, &vetor[i].tempo);
    }
    // Ordenar pelo instante de chegada. Chama a função ordenaInst.
    // Utilização da função qsort().
    qsort(vetor, nClientes, sizeof(Cliente), ordenaInst);
}
// Função para ordenar pelo instante de chegada.
int ordenaInst(const void *a, const void *b)
{
    Cliente clienteA = *(Cliente *)a, clienteB = *(Cliente *)b;
    if (clienteA.inst < clienteB.inst)
    {
        return -1;
    }
    // Analisa instante.
    else if (clienteA.inst == clienteB.inst)
    {
        // Analisa Prioridade no mesmo instante
        if (clienteA.idade > 64 || clienteB.idade > 64)
        {
            return clienteB.idade - clienteA.idade;
        }
        return 0;
    }
    else
    {
        return 1;
    }
}
// Função para verificar se o caixa está livre.
int caixaLivre(int *vetorCaixas, int t, int *iCaixas, int mCaixas)
{
    int i;
    for (i = 0; i < mCaixas; i++)
        if (t >= vetorCaixas[i])
        {
            *iCaixas = i;
            return 1;
        }

    return 0;
}
// Função para ocupar o caixa.
int ocupaCaixa(int *caixaLivre, Cliente *listaClientes, Fila *fila, int *head, int iCliente, int *iFila)
{
    int i, trueOrFalse = 0;

    // Remove o cliente da fila e reajusta os clientes que ainda estão na fila.
    if (*iFila > 0)
    {
        iCliente = *head;
        for (i = 0; i < *iFila - 1; i++)
        {
            Fila[i].idade = Fila[i + 1].idade;
            Fila[i].pos = Fila[i + 1].pos;
        }

        *head = Fila[0].pos;
        Fila[i].idade = -1;
        *iFila = *iFila - 1;
        trueOrFalse = 1;
    }

    // Ocupa o caixa.
    if (*caixaLivre)
    {
        *caixaLivre += listaClientes[iCliente].tempo;
    }
    else
    {
        *caixaLivre = listaClientes[iCliente].inst + listaClientes[iCliente].tempo;
    }

    return trueOrFalse;
}
// Funcão para inserir na fila.
void insereFila(Cliente *listaClientes, Fila *fila, int *head, int iCliente, int *iFila)
{
    int i = 0, j;

    if (!*iFila)
    {
        *head = iCliente;
    }

    if (listaClientes[iCliente].idade > 64)
    {
        while (fila[i].idade > listaClientes[iCliente].idade)
        {
            i++;
        }
        if (!i)
        {
            *head = iCliente;
        }
        for (j = *iFila; j > i; j--)
        {
            fila[j].idade = fila[j - 1].idade;
            fila[j].pos = fila[j - 1].pos;
        }
        fila[i].idade = listaClientes[iCliente].idade;
        fila[i].pos = iCliente;
    }
    else
    {
        fila[*iFila].idade = listaClientes[iCliente].idade;
        fila[*iFila].pos = iCliente;
    }

    *iFila = *iFila + 1;
}
// Função para imprimir a fila.
void imprimeFila(Fila *fila, int iFila)
{
    int i;
    if (fila[0].idade > 0)
    {
        for (i = 0; i < iFila; i++)
        {
            printf("%d ", fila[i].idade);
        }
    }
    else
    {
        printf("NULL");
    }
    printf("\n");
}
// Função que realiza as operações de caixa/fila.
void operacoes(Cliente *listaClientes, int mCaixas)
{
    int i, atualForaFila;
    int head = 0, j = 0, iCaixas = 0, iFila = 0;

    Fila fila[nClientes];
    for (i = 0; i < nClientes; i++)
    {
        fila[i].idade = fila[i].pos = -1;
    }
    int caixas[mCaixas];
    for (i = 0; i < mCaixas; i++)
    {
        caixas[i] = 0;
    }

    for (i = 0; i < nClientes; i++)
    {
        // Se o caixa estiver livre, o cliente atual vai direto pro caixa, sem passar pela fila.
        if (caixaLivre(caixas, listaClientes[i].inst, &iCaixas, mCaixas))
        {
            {
                atualForaFila = ocupaCaixa(&caixas[iCaixas], listaClientes, fila, &head, i, &iFila);
            }

            while (iFila > 0 && caixaLivre(caixas, listaClientes[i].inst, &iCaixas, mCaixas))
            {
                atualForaFila = ocupaCaixa(&caixas[iCaixas], listaClientes, fila, &head, i, &iFila);
            }

            if (atualForaFila)
            {
                insereFila(listaClientes, fila, &head, i, &iFila);
            }
        }
        // Se não houver caixas livres, insere na fila.
        else
        {
            insereFila(listaClientes, fila, &head, i, &iFila);
        }
        // A cada novo instante de chegada, imprime-se a fila.
        if (!(listaClientes[i].inst == listaClientes[i + 1].inst))
        {
            imprimeFila(fila, iFila);
        }
    }
}