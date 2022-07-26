#include <iostream>
using namespace std;

struct ARVORE
{
    int num, altD, altE;
    ARVORE *dir, *esq;
};
ARVORE *Rotacao_Esquerda(ARVORE *aux)
{
    ARVORE *aux1, *aux2;
    aux1 = aux->dir;
    aux2 = aux1->esq;
    aux->dir = aux2;
    aux1->esq = aux;
    if (aux->dir == NULL)
        aux->altD = 0;
    else if (aux->dir->altE > aux->dir->altD)
        aux->altD = aux->dir->altE + 1;
    else
        aux->altD = aux->dir->altD + 1;
    if (aux1->esq->altE > aux->esq->altD)
        aux1->altE = aux1->esq->altE + 1;
    else
        aux1->altE = aux1->esq->altD + 1;
    return aux1;
}
ARVORE *Rotacao_Direita(ARVORE *aux)
{
    ARVORE *aux1, *aux2;
    aux1 = aux->esq;
    aux2 = aux1->dir;
    aux->esq = aux2;
    aux1->dir = aux;
    if (aux->esq == NULL)
        aux->altE = 0;
    else if (aux->esq->altE > aux->esq->altD)
        aux->altE = aux->esq->altE + 1;
    else
        aux->altE = aux->esq->altD + 1;
    if (aux1->dir->altE > aux1->dir->altD)
        aux1->altD = aux1->dir->altE + 1;
    else
        aux1->altD = aux1->dir->altD + 1;
    return aux1;
}
ARVORE *Balanceamento(ARVORE *aux)
{
    int d, df;
    d = aux->altD - aux->altE;
    if (d == 2)
    {
        df = aux->dir->altD - aux->dir->altE;
        if (df >= 0)
            aux = Rotacao_Esquerda(aux);
        else
        {
            aux->dir = Rotacao_Direita(aux);
            aux = Rotacao_Esquerda(aux);
        }
    }
    else if (d == -2)
    {
        df = aux->esq->altD - aux->esq->altE;
        if (df <= 0)
            aux = Rotacao_Direita(aux);
        else
        {
            aux->esq = Rotacao_Esquerda(aux->esq);
            aux = Rotacao_Direita(aux);
        }
    }
    return aux;
}
ARVORE *Inserir(ARVORE *aux, int num)
{
    ARVORE *novo;
    if (aux == NULL)
    {
        novo = new ARVORE();
        novo->num = num;
        novo->altD = 0;
        novo->altE = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        aux = novo;
    }
    else if (num < aux->num) // esq
    {
        aux->esq = Inserir(aux->esq, num);
        if (aux->esq->altD > aux->esq->altE)
            aux->altE = aux->esq->altD + 1;
        else
            aux->altE = aux->esq->altE + 1;
        aux = Balanceamento(aux);
    }
    else // dir
    {
        aux->dir = Inserir(aux->dir, num);
        if (aux->dir->altD > aux->dir->altE)
            aux->altD = aux->dir->altD + 1;
        else
            aux->altD = aux->dir->altE + 1;
        aux = Balanceamento(aux);
    }
    return (aux);
}
void main()
{
    ARVORE *raiz = NULL;
    ARVORE *aux;

    int op, achou, numero;

    if (op == 1) // INSERÇÃO
    {
        cout << "Digite o numero a ser inserido";
        cin >> numero;
        raiz = Inserir(raiz, numero);
    }
}