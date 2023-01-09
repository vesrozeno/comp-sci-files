// Vitor Emanuel da Silva Rozeno - RA:211044539

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char tarefa[60];
    int dia, mes, ano;
} ToDo;

typedef struct
{
    int id;
    long posicao;
} Header;
int cadastrar_ToDo(ToDo **t, int quant, int tam);
void imprimir(ToDo **t, int quant);
void alterar_ToDo(ToDo **t, int quant);
void salvar(ToDo **t, int quant, char arq[]);
int ler_arquivo(ToDo **c, char arq[]);
int loadHeader(Header **head);
void KeySearch(Header **head, int quant_index, char arq[]);

int main()
{
    ToDo *tarefa[100];
    Header *header[100];
    char arquivo[] = {"ToDo.txt"};
    char arquivo_ind[] = {"Header.txt"};
    int menu, tam = 100, quant = 0;

    int x;

    quant = ler_arquivo(tarefa, arquivo);

    do
    {
        printf("\n\tMENU");
        printf("\n\t1) Cadastrar");
        printf("\n\t2) Alterar");
        printf("\n\t3) Imprimir");
        printf("\n\t4) Salvar");
        printf("\n\t5) Ler Arquivo");
        printf("\n\t6) Buscar tarefa no arquivo");
        printf("\n\t7) Sair\n");
        scanf("%d", &menu);
        getchar();
        switch (menu)
        {
        case 1:
            quant += cadastrar_ToDo(tarefa, quant, tam);
            break;
        case 2:
            alterar_ToDo(tarefa, quant);
            break;
        case 3:
            imprimir(tarefa, quant);
            break;
        case 4:
            salvar(tarefa, quant, arquivo);
            break;
        case 5:
            quant = ler_arquivo(tarefa, arquivo);
            break;
        case 6:
            x = loadHeader(header);
            if (x != -1)
                KeySearch(header, x, arquivo);
            break;
        default:
            if (menu != 7)
                printf("\n\tOpção inválida!\n");
        }
    } while (menu != 7);

    return 0;
}

int cadastrar_ToDo(ToDo **t, int quant, int tam)
{
    if (quant < tam)
    {
        ToDo *novo = malloc(sizeof(ToDo));

        printf("\nDigite a tarefa: ");
        scanf("%50[^\n]", novo->tarefa);

        printf("\nDigite o ID da tarefa: ");
        scanf("%d", &novo->id);

        printf("\nDigite a data prevista dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        t[quant] = novo;
        return 1;
    }
    else
    {
        printf("\nERRO! Vetor cheio.\n");
        return 0;
    }
}

void imprimir(ToDo **t, int quant)
{
    int i;

    printf("\n-------------Lista-de-Tarefas-------------\n");
    for (i = 0; i < quant; i++)
    {
        printf("ID: %d", t[i]->id);
        printf("\t%d = %2d/%2d/%4d\t%s\n", i + 1, t[i]->dia, t[i]->mes, t[i]->ano, t[i]->tarefa);
    }

    printf("------------------------------------------\n");
}

void alterar_ToDo(ToDo **t, int quant)
{
    int id;

    imprimir(t, quant);
    printf("\n\tDigite a tarefa a ser alterada: ");
    scanf("%d", &id);
    getchar();
    id--;
    if (id >= 0 && id < quant)
    {
        ToDo *novo = malloc(sizeof(ToDo));
        printf("\nDigite a nova tarefa: ");
        scanf("%50[^\n]", novo->tarefa);
        printf("\nDigite a data da tarefa (dd mm aaaa)");
    }
    else
    {
        printf("\n\tCodigo invalido!\n");
    }
}

void salvar(ToDo **t, int quant, char arq[])
{
    FILE *file = fopen(arq, "w");
    FILE *header = fopen("Header.txt", "w");
    int i;
    long posicao;

    if (file)
    {
        fprintf(file, "%d\n", quant);
        fprintf(header, "%d\n", quant);
        for (i = 0; i < quant; i++)
        {
            posicao = ftell(file);
            fputs(t[i]->tarefa, file);
            fputc('\n', file);
            fprintf(file, "%d %d %d %d\n", t[i]->id, t[i]->dia, t[i]->mes, t[i]->ano);
            fprintf(header, "%d %ld\n", t[i]->id, posicao);
        }
        fclose(file);
        fclose(header);
    }
    else
        printf("\n\tERRO AO ABRIR/CRIAR O ARQUIVO!\n");
}

int ler_arquivo(ToDo **c, char arq[])
{
    FILE *file = fopen(arq, "r");
    int quant = 0, i;
    ToDo *novo;
    if (file)
    {
        fscanf(file, "%d\n", &quant);
        for (i = 0; i < quant; i++)
        {
            novo = malloc(sizeof(ToDo));
            fscanf(file, "%50[^\n]", novo->tarefa);
            fscanf(file, "%d %d %d %d\n", &novo->id, &novo->dia, &novo->mes, &novo->ano);
            c[i] = novo;
        }
    }
    else
        printf("\n\tErro com o arquivo!\n");

    fclose(file);

    return quant;
}

int loadHeader(Header **head)
{
    FILE *header = fopen("Header.txt", "r");
    if (!header)
    {
        printf("\nErro ao abrir header");
        return -1;
    }

    int n, i, id;
    long posicao;
    fscanf(header, "%d", &n);
    Header *novo;
    for (i = 0; i < n; i++)
    {
        novo = malloc(sizeof(Header));
        fscanf(header, "%d %ld", &novo->id, &novo->posicao);
        head[i] = novo;
    }
    printf("\n\tCadastros:\n");
    for (i = 0; i < n; i++)
    {
        printf("\tchave: %d\n", head[i]->id);
    }
    fclose(header);
    return n;
}

void KeySearch(Header **head, int quant_index, char arq[])
{
    int i, id;
    char tarefa[60];
    int dia, mes, ano, aux;

    FILE *file = fopen(arq, "r");
    if (!file)
    {
        printf("\nErro ao abrir cadastros.");
        return;
    }

    printf("\nDigite a chave da ToDo: ");
    scanf("%d", &id);
    getchar();

    for (i = 0; i < quant_index; i++)
    {
        if (id == head[i]->id)
        {
            fseek(file, head[i]->posicao, SEEK_SET);
            fscanf(file, "%50[^\n]", tarefa);
            fscanf(file, " %d %d %d %d", &aux, &dia, &mes, &ano);
            printf("%s : %d/%d/%d\n", tarefa, dia, mes, ano);
            return;
        }
    }
    fclose(file);
    printf("\nAluno não encontrado.");
}
