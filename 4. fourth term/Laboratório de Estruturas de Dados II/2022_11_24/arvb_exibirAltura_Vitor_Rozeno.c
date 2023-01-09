/*

    Vitor Emanuel da Silva Rozeno
        RA : 211044539 Avaliação -
    Lab ED II

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define MIN 1
#define boolean int
#define true 1
#define false 0
#define NMAXREGS 20

typedef struct no
{
    int item[MAX + 1], count;
    struct no *link[MAX + 1];
} no;
no *raiz;

typedef struct arvb
{
    int ordem;
    int nregs;
    int chave[NMAXREGS + 1];
    struct arvb *filha[NMAXREGS + 2];

} ArvB, NoArvB;

void procura(no *noSelecionado);
void divideNo(int item, int *pval, int pos, no *varNode, no *filho, no **novoNo);
no *criarNo(int item, no *filho);
void InserirValor(int item, int pos, no *varNode, no *filho);
int setNo(int item, int *pval, no *varNode, no **filho);
void inserir(int item);
int localiza(no *raiz, int item);
boolean NoComMenosChavesQuePermitido(NoArvB *no);
boolean NoComMaisChavesQuePossivel(NoArvB *no);
void RemoveChaveEmNo(NoArvB *no, int pos);
void TrataNoComMenosChavesQuePermitido(NoArvB **no, int pos);
void TrocaChaveComAntecessora(NoArvB *no, int pos);
boolean BuscaChaveNoArvB(NoArvB *no, int chave, int *pos);
boolean RemoveArvBRec(NoArvB **no, int chave, boolean *underflow);
boolean RemoveArvB(ArvB **arvore, int chave);
void exibeAltura(no *noSelecionado, int *altura);

int main()
{
    int item, ch, menu;
    no *chave;
    int altura = 0;

    do
    {
        printf("\n\t\tMENU\n\t1) Inserir\n\t2) Localizar\n\t3)Exibir árvore com altura\n\t4) Sair\n");
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
            exibeAltura(raiz, &altura);
            break;
        case 4:
            printf("\n\tSaindo.......\n");
            break;
        default:
            printf("Entrada inválida!");
        }
    } while (menu != 4);
}
void inserir(int item)
{
    int flag, i;
    no *filho;
    flag = setNo(item, &i, raiz, &filho);
    if (flag)
    {
        raiz = criarNo(i, filho);
        printf("\n\tElemento inserido!\n");
    }
}
int setNo(int item, int *pval, no *varNode, no **filho)
{
    int pos;
    if (!varNode)
    {
        *pval = item;
        *filho = NULL;
        return 1;
    }
    if (item < varNode->item[1])
    {
        pos = 0;
    }
    else
    {
        for (pos = varNode->count; (item < varNode->item[pos] && pos > 1);
             pos--)
            ;
        if (item == varNode->item[pos])
        {
            printf("\n\tNão permite valor duplicado!\n");
            return 0;
        }
    }
    if (setNo(item, pval, varNode->link[pos], filho))
    {
        if (varNode->count < MAX)
        {
            InserirValor(*pval, pos, varNode, *filho);
        }
        else
        {
            divideNo(*pval, pval, pos, varNode, *filho, filho);
            return 1;
        }
    }

    return 0;
}
void InserirValor(int item, int pos, no *varNode, no *filho)
{
    int j = varNode->count;
    while (j > pos)
    {
        varNode->item[j + 1] = varNode->item[j];
        varNode->link[j + 1] = varNode->link[j];
        j--;
    }
    varNode->item[j + 1] = item;
    varNode->link[j + 1] = filho;
    varNode->count++;
}

no *criarNo(int item, no *filho)
{
    no *novoNo;
    novoNo = (no *)malloc(sizeof(no));
    novoNo->item[1] = item;
    novoNo->count = 1;
    novoNo->link[0] = raiz;
    novoNo->link[1] = filho;
    return novoNo;
}

void divideNo(int item, int *pval, int pos, no *varNode, no *filho, no **novoNo)
{
    int mediana, j;
    if (pos > MIN)
        mediana = MIN + 1;
    else
        mediana = MIN;
    *novoNo = (no *)malloc(sizeof(no));
    j = mediana + 1;
    while (j <= MAX)
    {
        (*novoNo)->item[j - mediana] = varNode->item[j];
        (*novoNo)->link[j - mediana] = varNode->link[j];
        j++;
    }
    varNode->count = mediana;
    (*novoNo)->count = MAX - mediana;
    if (pos <= MIN)
    {
        InserirValor(item, pos, varNode, filho);
    }
    else
    {
        InserirValor(item, pos - mediana, *novoNo, filho);
    }
    *pval = varNode->item[varNode->count];
    (*novoNo)->link[0] = varNode->link[varNode->count];
    varNode->count--;
}
void procura(no *noSelecionado)
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
void exibeAltura(no *noSelecionado, int *altura)
{
    int i;
    if (noSelecionado)
    {
        for (i = 0; i < noSelecionado->count; i++)
        {
            *altura = *altura + 1;
            exibeAltura(noSelecionado->link[i], altura);
            printf("%d", *altura);
            printf(" - ");
            printf("%d", noSelecionado->item[i + 1]);
            printf("\n");
        }
        *altura = *altura + 1;
        exibeAltura(noSelecionado->link[i], altura);
    }
}
int localiza(no *raiz, int item)
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
boolean RemoveArvB(ArvB **arvore, int chave)
{
    if ((*arvore) == NULL)
    {
        printf("Erro em RemoveArvB: Árvore inexistente\n");
        exit(1);
    }
    boolean underflow = false;

    if (RemoveArvBRec(arvore, chave, &underflow))
    { /* A chave foi removida */

        /* Se o underflow chegou até a raiz da arvore, entao a raiz antiga
           deve ser eliminada e a nova será a sua única filha, reduzindo
           assim a altura da arvore em 1.
        */

        if (underflow)
        {
            NoArvB *no = *arvore;
            *arvore = (*arvore)->filha[0];
            free(no);
        }
        return (true);
    }
    return (false);
}

boolean RemoveArvBRec(NoArvB **no, int chave, boolean *underflow)
{
    int pos;

    /* Verifica se a chave está no nó atual. Se tiver e esse nó for uma
    folha, realiza a remoção. Caso contrário, troca a chave pela
    antecessora e continua o procedimento recursivo para remoção. */

    if (BuscaChaveNoArvB(*no, chave, &pos))
    { /* a chave está no nó deste nível */
        if ((*no)->filha[pos] != NULL)
        {
            /* O nó atual não é uma folha,
                      então a chave precisa ser trocada pela antecessora, reduzindo ao caso de remoção na folha. */

            TrocaChaveComAntecessora(*no, pos); /* troca a chave pela sua antecessora -- i.e., a
                           chave mais à direita na árvore à esquerda. continua o procedimento recursivo para
                 reencontrar e remover a chave do nó folha */

            RemoveArvBRec(&((*no)->filha[pos]), chave, underflow);
            /* trata underflow, se for o caso, após a remoção da chave */
            if (*underflow)
                TrataNoComMenosChavesQuePermitido(no, pos);
        }
        else
        { /* achou a chave no nó folha, então ela pode ser removida. */
            RemoveChaveEmNo(*no, pos);
        }
        /* verifica se a folha ficou em underflow */

        (*underflow) = NoComMenosChavesQuePermitido(*no);
        return (true); /* remoção bem sucedida */
    }
    else
    { /* procura a chave nos nós abaixo */
        if ((*no)->filha[pos] != NULL)
        {
            if (RemoveArvBRec(&((*no)->filha[pos]), chave, underflow))
            {
                /* a chave foi encontrada e removida da folha (raiz da árvore
                filha). Trata um possível underflow e verifica novamente se
                ele será propagado para cima (volta da recursão). */
                if (*underflow)
                    TrataNoComMenosChavesQuePermitido(no, pos);
                (*underflow) = NoComMenosChavesQuePermitido(*no);
                return (true);
            }
            else
            {
                return (false); /* chego na folha e não achou a chave */
            }
        }
        else
        { /* estamos na raiz e a chave não está neste nível, logo ela não existe. */
            (*underflow) = false;
            return (false);
        }
    }
}

boolean BuscaChaveNoArvB(NoArvB *no, int chave, int *pos)
{
    for ((*pos) = 0; (no->chave[*pos] < chave) && (*pos) < no->nregs; (*pos)++)
        ;

    /* "pos" contém a posição da chave no nó */
    if (((*pos) < no->nregs) && (no->chave[*pos] == chave))
        return (true);

    /* "pos" contém a posição da árvore filha na qual a chave poderá ser encontrada */
    return (false);
}

void TrocaChaveComAntecessora(NoArvB *no, int pos)
{
    ArvB *no_aux;
    int chave_aux;

    no_aux = no->filha[pos];                     /* árvore filha à esquerda da chave na posição "pos" */
    while (no_aux->filha[no_aux->nregs] != NULL) /* busca a chave mais à direira na àrvore esquerda (i.e., a antecessora da chave que está em "no" na posição "pos") */
        no_aux = no_aux->filha[no_aux->nregs];

    /* troca a chave por sua antecessora na árvore B */
    chave_aux = no->chave[pos];
    no->chave[pos] = no_aux->chave[no_aux->nregs - 1];
    no_aux->chave[no_aux->nregs - 1] = chave_aux;
}

void TrataNoComMenosChavesQuePermitido(NoArvB **no, int pos)
{
    int chave, i, j;
    NoArvB *irma_esq = NULL, *filha = NULL, *irma_dir = NULL;

    filha = (*no)->filha[pos];

    if (pos > 0)
    { /* existe irmã à esquerda da filha */
        irma_esq = (*no)->filha[pos - 1];
        if (irma_esq->nregs > (((*no)->ordem) / 2))
        { /* A irmã à esquerda tem chaves para emprestar. A sua última chave sobe
para o nó pai e a chave do nó pai  desce para a filha na posição mais à esquerda. A filha à direira da chave que
subiu passa a ser filha à esquerda daquela que desceu.*/
            chave = (*no)->chave[pos - 1];
            (*no)->chave[pos - 1] = irma_esq->chave[irma_esq->nregs - 1];
            NoArvB *filha_esq = irma_esq->filha[irma_esq->nregs];
            RemoveChaveEmNo((*no)->filha[pos - 1], (*no)->filha[pos - 1]->nregs);
            filha->nregs++;
            filha->filha[0] = filha_esq;
            filha->chave[0] = chave;
            return;
        }
    }

    if (pos < (*no)->nregs)
    { /* existe irmã à direita */
        irma_dir = (*no)->filha[pos + 1];
        if (irma_dir->nregs > (((*no)->ordem) / 2))
        { /* A irmã à direita tem chaves para
emprestar. A sua primeira chave sobe para o nó pai e a chave do nó pai desce para a filha na posição mais à
direita. A filha à esquerda da chave que subiu passa a ser filha à direita daquela que desceu. */
            chave = (*no)->chave[pos];
            (*no)->chave[pos] = irma_dir->chave[0];
            NoArvB *filha_dir = irma_dir->filha[0];
            RemoveChaveEmNo((*no)->filha[pos + 1], 0);
            filha->nregs++;
            filha->filha[filha->nregs] = filha_dir;
            filha->chave[filha->nregs - 1] = chave;
            return;
        }
    }
}

void RemoveChaveEmNo(NoArvB *no, int pos)
{
    int i;
    /* desloca as chaves e filhas para trás */
    for (i = pos; i < no->nregs; i++)
    {
        no->chave[i] = no->chave[i + 1];
        no->filha[i] = no->filha[i + 1];
    }
    /* completa o deslocamento para a filha à direita da última chave */
    no->filha[i] = no->filha[i + 1];
    no->filha[i + 1] = NULL;
    /* ajusta o número de registros */
    no->nregs--;
}

boolean NoComMaisChavesQuePossivel(NoArvB *no)
{
    return (no->nregs > no->ordem);
}

boolean NoComMenosChavesQuePermitido(NoArvB *no)
{
    return (no->nregs < (no->ordem / 2));
}