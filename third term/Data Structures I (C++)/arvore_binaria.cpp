#include <iostream>
using namespace std;
struct ARVORE
{
    int num;
    ARVORE *esq, *dir;
};
ARVORE *Inserir(ARVORE *aux, int num)
{
    if (aux == NULL)
    {
        aux = new ARVORE();
        aux->num = num;
        aux->esq = NULL;
        aux->dir = NULL;
    }
    else if (num < aux->num)
        aux->esq = Inserir(aux->esq, num);
    else
        aux->dir = Inserir(aux->dir, num);
    return aux;
}

int Consultar(ARVORE *aux, int num, int achou)
{
    if (aux != NULL && achou == 0)
    {
        if (aux->num == num)
            achou = 1;
        else if (num < aux->num)
            achou = Consultar(aux->esq, num, achou); // esq
        else
            achou = Consultar(aux->dir, num, achou); // dir
    }
    return achou;
}

void MostrarEmOrdem(ARVORE *aux)
{
    if (aux != NULL)
    {
        MostrarEmOrdem(aux->esq);
        cout << aux->num;
        MostrarEmOrdem(aux->dir);
    }
}

void MostrarPreOrdem(ARVORE *aux)
{
    if (aux != NULL)
    {
        cout << aux->num;
        MostrarPreOrdem(aux->esq);
        MostrarPreOrdem(aux->dir);
    }
}

void MostrarPosOrdem(ARVORE *aux)
{
    if (aux != NULL)
    {
        MostrarPosOrdem(aux->esq);
        MostrarPosOrdem(aux->dir);
        cout << aux->num;
    }
}

ARVORE *Remover(ARVORE *aux, int num)
{
    ARVORE *p, *p2;
    if (aux->num == num)
    {
        if (aux->esq == aux->dir) // NÃO TEM FILHOS
        {
            delete (aux);
            return NULL;
        }
        else if (aux->esq == NULL) // NÃO TEM FILHOS À ESQUERDA
        {
            p = aux->dir;
            delete (aux);
            return p;
        }
        else if (aux->dir == NULL) // NÃO TEM FILHOS À DIREITA
        {
            p = aux->esq;
            delete (aux);
            return p;
        }
        else // TEM FILHOS EM AMBOS OS LADOS
        {
            p2 = aux->dir;
            p = aux->dir;
            while (p->esq != NULL)
                p = p->esq;
            p->esq = aux->esq;
            delete (aux);
            return p2;
        }
    }
    else if (aux->num < num)
    {
        aux->dir = Remover(aux->dir, num);
    }
    else
        aux->esq = Remover(aux->esq, num);
    return aux;
}

ARVORE *Desalocar(ARVORE *aux)
{
    if (aux != NULL)
    {
        aux->esq = Desalocar(aux->esq);
        aux->dir = Desalocar(aux->dir);
        delete (aux);
    }
    return NULL;
}

int main()
{
    ARVORE *raiz = NULL;
    ARVORE *aux;
    int op, numero, achou;
    do
    {
        cout << "Digite a OP:> ";
        cin >> op;
        if (op == 1) // INSERÇÃO
        {
            cout << "Digite o numero a ser inserido:> ";
            cin >> numero;
            raiz = Inserir(raiz, numero);
        }
        if (op == 2) // CONSULTAR
        {
            if (raiz == NULL)
                cout << "Arvore Vazia!";
            else
            {
                cout << "Digite o no a ser consultado";
                cin >> numero;

                achou = 0;

                achou = Consultar(raiz, numero, achou);
                if (achou == 0)
                    cout << "Numero nao encontrado...";
                else
                    cout << "Numero encontrado";
            }
        }

        if (op == 3) // MOSTRAR EM ORDEM
        {
            if (raiz == NULL)
                cout << "Arvore Vazia!";
            else
                MostrarEmOrdem(raiz);
        }

        if (op == 4) // MOSTRAR PRE ORDEM
        {
            if (raiz == NULL)
                cout << "Arvore Vazia!";
            else
                MostrarPreOrdem(raiz);
        }

        if (op == 5) // MOSTRAR POS ORDEM
        {
            if (raiz == NULL)
                cout << "Arvore Vazia!";
            else
                MostrarPosOrdem(raiz);
        }

        if (op == 6) // REMOVER
        {
            if (raiz == NULL)
                cout << "Arvore Vazia";
            else
            {
                cout << "Digite o numero a ser removido:>";
                cin >> numero;
                achou = 0;
                achou = Consultar(raiz, numero, achou);
                if (achou == 0)
                    cout << "Numero nao encontrado";
                else
                    raiz = Remover(raiz, numero);
            }
        }

        if (op == 7) // DESALOCAR
        {
            if (raiz == NULL)
                cout << "Arvore Vazia!";
            else
                raiz = Desalocar(raiz);
        }

        if (op == 8)
            cout << "Saindo...";

    } while (op != 8);

    return 0;
}