/*

Vitor Emanuel da Silva Rozeno
RA: 211044539
Avaliação - Lab ED II

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 3
#define MIN 2
typedef struct No
{
    int item[MAX + 1], count;
    struct No *link[MAX + 1];
} No;
No *raiz;

void procura(No *noSelecionado);
void divideNo(int item, int *pval, int pos, No *no, No *filho, No **novoNo);
No *criarNo(int item, No *filho);
void InserirValor(int item, int pos, No *no, No *filho);
int setNo(int item, int *pval, No *no, No **filho);
void inserir(int item);
int localiza(No *raiz, int item);

int main()
{
    int item, ch, menu;
    No *chave;

    do
    {
        printf("\n\t\tMENU\n\t1) Inserir\n\t2) Localizar\n\t3) Sair\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            printf("\nDigite o item a ser inserido: ");
            scanf("%d", &item);
            inserir(item);
            break;
        case 2:
            printf("\nDigite o item a ser localizado: ");
            scanf("%d", &item);

            if (!localiza(raiz, item))
            {
                printf("\n\tElemento não encontrado!\n");
            }
            break;
        case 3:
            printf("\n\tSaindo.......\n");
            break;
        default:
        }
    } while (menu != 3);
}
void inserir(int item)
{
    int flag, i;
    No *filho;
    flag = setNo(item, &i, raiz, &filho);
    if (flag)
    {
        raiz = criarNo(i, filho);
        printf("\n\tElemento inserido!\n");
    }
}
int setNo(int item, int *pval, No *no, No **filho)
{
    int pos;
    if (!no)
    {
        *pval = item;
        *filho = NULL;
        return 1;
    }
    if (item < no->item[1])
    {
        pos = 0;
    }
    else
    {
        for (pos = no->count; (item < no->item[pos] && pos > 1);
             pos--)
            ;
        if (item == no->item[pos])
        {
            printf("\n\tNão permite valor duplicado!\n");
            return 0;
        }
    }
    if (setNo(item, pval, no->link[pos], filho))
    {
        if (no->count < MAX)
        {
            InserirValor(*pval, pos, no, *filho);
        }
        else
        {
            divideNo(*pval, pval, pos, no, *filho, filho);
            return 1;
        }
    }

    return 0;
}
void InserirValor(int item, int pos, No *no, No *filho)
{
    int j = no->count;
    while (j > pos)
    {
        no->item[j + 1] = no->item[j];
        no->link[j + 1] = no->link[j];
        j--;
    }
    no->item[j + 1] = item;
    no->link[j + 1] = filho;
    no->count++;
}

No *criarNo(int item, No *filho)
{
    No *novoNo;
    novoNo = (No *)malloc(sizeof(No));
    novoNo->item[1] = item;
    novoNo->count = 1;
    novoNo->link[0] = raiz;
    novoNo->link[1] = filho;
    return novoNo;
}

void divideNo(int item, int *pval, int pos, No *no, No *filho, No **novoNo)
{
    int mediana, j;
    if (pos > MIN)
        mediana = MIN + 1;
    else
        mediana = MIN;
    *novoNo = (No *)malloc(sizeof(No));
    j = mediana + 1;
    while (j <= MAX)
    {
        (*novoNo)->item[j - mediana] = no->item[j];
        (*novoNo)->link[j - mediana] = no->link[j];
        j++;
    }
    no->count = mediana;
    (*novoNo)->count = MAX - mediana;
    if (pos <= MIN)
    {
        InserirValor(item, pos, no, filho);
    }
    else
    {
        InserirValor(item, pos - mediana, *novoNo, filho);
    }
    *pval = no->item[no->count];
    (*novoNo)->link[0] = no->link[no->count];
    no->count--;
}
void procura(No *noSelecionado)
{
    int i;
    if (noSelecionado)
    {
        for (i = 0; i < noSelecionado->count; i++)
        {
            procura(noSelecionado->link[i]);
            printf("%d ", noSelecionado->item[i + 1]);
        }
        procura(noSelecionado->link[i]);
    }
}
int localiza(No *raiz, int item)
{
    int i;
    if (raiz)
    {
        for (i = 0; i < raiz->count; i++)
        {
            localiza(raiz->link[i], item);
            if (raiz->item[i + 1] == item)
            {
                printf("\n\tElemento encontrado!: %d \n", raiz->item[i + 1]);
                printf("\n\tÁrvore: ");
                procura(raiz);
                printf("\n\n");
                return 1;
            }
        }
        localiza(raiz->link[i], item);
    }
    return 0;
}