#include <iostream>
using namespace std;

typedef struct
{
    int valor;
} tipo_dado;

typedef struct no
{
    tipo_dado info;
    struct no *dir;
    struct no *esq;
} no;

typedef struct no *tree;

void Definir(tree t)
{
    t = NULL;
}

bool Vazia(tree t)
{
    if (t == NULL)
    {
        return (true);
    }
    return (false);
}

tree criaRaiz(tree t, tipo_dado elem)
{
    no *t = new no;

    if (!t)
    {
        cout << "Nao foi possivel criar o no raiz \n";
        return;
    }
    t->info = elem;
    t->dir = NULL;
    t->esq = NULL;

    return (t);
}

bool insereEsquerda(tree pai, tipo_dado elem)
{
    if (Vazia(pai))
    {
        return false;
    }
    if (pai->esq != NULL)
    {
        cout << "Ja possui filho a esquerda. \n";
        return false;
    }
    pai->esq = malloc(sizeof(struct no));

    if (!pai->esq)
    {
        cout << "Nao foi possivel criar o no. \n";
        return;
    }
    pai->esq->info = elem;
    pai->esq->dir = NULL;
    pai->esq->esq = NULL;
    return true;
}

bool insereDireita(tree pai, tipo_dado elem)
{
    if (Vazia(pai))
    {
        return false;
    }
    if (pai->dir != NULL)
    {
        cout << "Ja possui filho a direita. \n";
        return false;
    }
    pai->dir = malloc(sizeof(struct no));

    if (!pai->dir)
    {
        cout << "Nao foi possivel criar o no. \n";
        return;
    }
    pai->dir->info = elem;
    pai->dir->dir = NULL;
    pai->dir->esq = NULL;
    return true;
}
// Retorna a altura (profundidade) da AB
int Altura(tree t)
{
    if (Vazia(t))
    {
        return 0;
    }

    int altE = Altura(t->esq);
    int altD = Altura(t->dir);

    if (altE > altD)
    {
        return (altE + 1);
    }

    return (altD + 1);
    // altura = max(altE, altD)+1
}

bool Balanceada(tree t)
{
    if (Vazia(t))
    {
        return true;
    }
    else if (t->esq == NULL && t->dir == NULL) // se nao tem filhos
    {
        return true;
    }
    else if (t->esq != NULL && t->dir != NULL) // se tem duas sub-arvores
    {
        return (Balanceada(t->esq) && Balanceada(t->dir));
    }
    else if (t->esq != NULL) // se tem um unico filho a esquerda
    {
        return (Altura(t->esq) == 1);
    }
    else // se tem um unico filho a direita
    {
        return (Altura(t->dir) == 1);
    }
}

int numeroNos(tree t)
{
    if (Vazia(t))
        return 0;
    int nDir = numeroNos(t->dir);
    int nEsq = numeroNos(t->esq);

    return (nDir + nEsq + 1);
}
bool perfeitamenteBalanceada(tree t)
{
    if (Vazia(t))
        return true;
    else if (t->esq == NULL && t->dir == NULL)
        return true;
    else if (t->esq != NULL && t->dir != NULL)
        return (perfeitamenteBalanceada(t->esq) && perfeitamenteBalanceada(t->dir));
    // para ser perfeitamente balanceada o numero de nos pode diferir em, no maximo, 1
    else if (t->esq != NULL)
        return (numeroNos(t->esq) == 1);
    else
        return (numeroNos(t->dir) == 1);
}

void Visita(tree t)
{
    cout << "Valor" << t->info.valor;
}

void preOrdem(tree t)
{
    if (t != NULL)
    {
        Visita(t);
        preOrdem(t->esq);
    }
}

void inOrdem(tree t)
{
    if (t != NULL)
    {
        inOrdem(t->esq);
        Visita(t);
        inOrdem(t->dir);
    }
}

void posOrdem(tree t)
{
    if (t != NULL)
    {
        posOrdem(t->esq);
        posOrdem(t->dir);
        Visita(t);
    }
}
