#include <stdio.h>
#include <stdlib.h>
typedef struct No
{
    int valor;
    struct No *proximo;
} No;
typedef struct
{
    No *inicio;
    int tam;
} Lista;

void listar(Lista *lista)
{
    No *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tam);
    while (inicio != NULL)
    {
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}
void remover_Inicio(Lista *lista)
{
    No *aux;
    if (lista->inicio)
    {
        aux = lista->inicio;
        lista->inicio = aux->proximo;

        free(aux);
        lista->tam--;
    }
    else
    {
        printf("Lista Vazia");
    }
}
void remover_Fim(Lista *lista)
{
    No *aux, *anterior;
    if (lista->inicio)
    {

        aux = lista->inicio;

        if (aux->proximo)
        {

            while (aux->proximo != NULL)
            {
                anterior = aux;
                aux = aux->proximo;
            }
            anterior->proximo = NULL;
            aux = NULL;
            free(aux);
            lista->tam--;
        }
        else
        {
            lista->inicio = NULL;
            free(aux);
            lista->tam--;
        }
    }
    else
        printf("Lista Vazia");
}
void criar_lista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}
void inicio(Lista *lista, int num)
{
    No *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else
        printf("Erro de memoria!\n");
}
void fim(Lista *lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;
        if (lista->inicio == NULL)
            lista->inicio = novo;
        else
        {
            aux = lista->inicio;
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro de memoria!\n");
}
void meio(Lista *lista, int num, int anterior)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->valor = num;
        if (lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            while (aux->valor != anterior && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro memoria!\n");
}
int main()
{
    int opcao, valor, anterior;
    Lista lista;
    criar_lista(&lista);
    do
    {
        printf("\n\t0 - Sair\n\t1 - Inicio \n\t2 - Fim\n\t3 - Meio\n\t4 - Lista\n\t5 - Remover no Inicio\n\t6 - Remover no Fim\n");
        scanf("%d", &opcao);
        switch (opcao)
        {

        case 1:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            inicio(&lista, valor);
            break;
        case 2:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            fim(&lista, valor);
            break;
        case 3:
            printf("Digite o valor e a posicao anterior: ");
            scanf("%d%d", &valor, &anterior);
            meio(&lista, valor, anterior);
            break;
        case 4:
            listar(&lista);
            break;
        case 5:
            remover_Inicio(&lista);
            break;
        case 6:
            remover_Fim(&lista);
            break;
        default:
            if (opcao != 0)
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
    return 0;
}
