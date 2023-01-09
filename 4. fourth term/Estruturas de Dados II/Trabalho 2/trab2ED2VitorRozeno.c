/*
Vitor Emanuel da Silva Rozeno - RA 211044539
Trabalho 2 - Compressor de textos com codificação Huffman

Código feito com base nas aulas do laboratório de ED2.

A descompressão de arquivos gera alguns problemas nos primeiros e últimos caracteres,
enquantos os caracteres do meio seguem normais.


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 256

typedef struct node
{
    unsigned char carac;
    int freq;
    struct node *left, *right, *next;
} Node;

typedef struct
{
    Node *begin;
    int size;
} List;

/*
================================================================
Protótipos das Funções
================================================================
*/
int frequency(unsigned char text[], unsigned int table[]);
void init_list(List *list);
void ordered_insert(List *list, Node *node);
void fill_list(unsigned int table[], List *list);
Node *remove_first(List *list);
Node *init_tree(List *list);
int tree_height(Node *root);
char **dictionary_allocation(int col);
void init_dictionary(char **dict, Node *root, char *path, int col);
char *code(char **dict, unsigned char *text);
char *decode(unsigned char text[], Node *root);
void compress(unsigned int frequencyTable[], char file[]);
void decompress(unsigned int frequencyTable[], char file[]);
int string_size(char **dict, unsigned char *text);
unsigned char convert_byte(char *vet, int n);
void convert(char ch, char *vet);

/*
================================================================
Função Principal
================================================================
*/
int main()
{

    unsigned int frequencyTable[SIZE];
    char file[50];
    int menu;

    do
    {
        printf("\n\t\tUnespZip:\n\t1 - Comprimir\n\t2 - Descomprimir\n\t3 - Sair\n");

        scanf("%d", &menu);
        switch (menu)
        {
        case 1:

            printf("\n\t(Compressão) Digite o nome do arquivo: ");
            scanf("%s", file);
            compress(frequencyTable, file);
            break;
        case 2:

            printf("\n\t(Descompressão) Digite o nome do arquivo: ");
            scanf("%s", file);
            decompress(frequencyTable, file);
            break;
        case 3:
            printf("\n\t\tSaindo ...\n\n");
            break;
        default:
        {
            printf("\n\t\tEntrada inválida.\n\n");
        }
        }
    } while (menu != 3);
    return 0;
}

/*
================================================================
Funções da lista
================================================================
*/
int frequency(unsigned char text[], unsigned int table[])
{
    int i = 0;

    int contador = 0;

    for (i = 0; i < SIZE; i++)
    {
        table[i] = 0;
    }

    i = 0;

    while (text[i] != '\0')
    {
        table[text[i]]++;
        i++;
    }

    for (i = 0; i < SIZE; i++)
    {
        if (table[i] > 0)
        {
            contador++;
        }
    }

    return contador;
}
void init_list(List *list)
{
    list->begin = NULL;
    list->size = 0;
}
void ordered_insert(List *list, Node *node)
{
    Node *aux;

    if (list->begin == NULL)
    {
        list->begin = node;
    }

    else if (node->freq < list->begin->freq)
    {
        node->next = list->begin;
        list->begin = node;
    }
    else
    {
        aux = list->begin;
        while (aux->next && aux->next->freq <= node->freq)
            aux = aux->next;
        node->next = aux->next;
        aux->next = node;
    }

    list->size++;
}
void fill_list(unsigned int table[], List *list)
{
    int i;
    Node *new;
    for (i = 0; i < SIZE; i++)
    {
        if (table[i] > 0)
        {
            new = malloc(sizeof(Node));
            if (new)
            {
                new->carac = i;
                new->freq = table[i];
                new->right = NULL;
                new->left = NULL;
                new->next = NULL;

                ordered_insert(list, new);
            }
            else
            {
                printf("\tErro em fill_list.\n");
                break;
            }
        }
    }
}
Node *remove_first(List *list)
{
    Node *aux = NULL;

    if (list->begin)
    {
        aux = list->begin;
        list->begin = aux->next;
        aux->next = NULL;
        list->size--;
    }

    return aux;
}
/*
================================================================
Funções da árvore
================================================================
*/
Node *init_tree(List *list)
{
    Node *first, *second, *new;
    while (list->size > 1)
    {
        first = remove_first(list);
        second = remove_first(list);
        new = malloc(sizeof(Node));

        if (new)
        {
            new->carac = '+';
            new->freq = first->freq + second->freq;
            new->left = first;
            new->right = second;
            new->next = NULL;

            ordered_insert(list, new);
        }
        else
        {
            printf("\n\tErro em init_tree.\n");
            break;
        }
    }
    return list->begin;
}
int tree_height(Node *root)
{
    int left, right;

    if (root == NULL)
    {
        return -1;
    }
    else
    {
        left = tree_height(root->left) + 1;
        right = tree_height(root->right) + 1;

        if (left > right)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}
/*
================================================================
Funções do dicionário - árvore
================================================================
*/
char **dictionary_allocation(int col)
{
    char **dict;
    int i;

    dict = malloc(sizeof(char *) * SIZE);

    for (i = 0; i < SIZE; i++)
        dict[i] = calloc(col, sizeof(char));

    return dict;
}
void init_dictionary(char **dict, Node *root, char *path, int col)
{
    char left[col], right[col];

    if (root->left == NULL && root->right == NULL)
        strcpy(dict[root->carac], path);
    else
    {
        strcpy(left, path);
        strcpy(right, path);

        strcat(left, "0");
        strcat(right, "1");

        init_dictionary(dict, root->left, left, col);
        init_dictionary(dict, root->right, right, col);
    }
}
/*
================================================================
Funções de codificação, decodificação, compressão e descompressão
================================================================
*/
char *code(char **dict, unsigned char *text)
{

    int i = 0, size = string_size(dict, text);
    char *coded = calloc(size, sizeof(char));

    while (text[i] != '\0')
    {
        strcat(coded, dict[text[i]]);
        i++;
    }
    return coded;
}
char *decode(unsigned char text[], Node *root)
{
    int i = 0;
    Node *aux = root;
    char temp[2];
    char *decoded = calloc(strlen(text), sizeof(char));

    while (text[i] != '\0')
    {
        if (text[i] == '0')
            aux = aux->left;
        else
            aux = aux->right;

        if (aux->left == NULL && aux->right == NULL)
        {
            temp[0] = aux->carac;
            temp[1] = '\0';
            strcat(decoded, temp);
            aux = root;
        }

        i++;
    }
    return decoded;
}
void compress(unsigned int frequencyTable[], char file[])
{
    unsigned char vet[9], carac;
    char **dict, *codificado;
    FILE *codedFile = fopen("compressedFile.huf", "w");
    FILE *auxFile = fopen("aux.txt", "w");
    FILE *arquivo = fopen(file, "r");

    if (!arquivo || !auxFile || !codedFile)
    {
        printf("\nErro ao abrir o arquivo.");
        return;
    }

    int i = 0, pos, tableSize, col, codeSize;

    List list;
    Node *tree;

    fseek(arquivo, 0, SEEK_END);

    long size = ftell(arquivo);
    char *text = malloc(sizeof(char) * size + 1);
    char *aux = malloc(sizeof(char) * size);

    rewind(arquivo);

    while (size != pos)
    {
        fgets(aux, size + 1, arquivo);
        strcat(text, aux);
        pos = ftell(arquivo);
    }

    tableSize = frequency(text, frequencyTable);

    init_list(&list);
    fill_list(frequencyTable, &list);

    tree = init_tree(&list);
    col = tree_height(tree) + 1;
    dict = dictionary_allocation(col);

    init_dictionary(dict, tree, "", col);

    codificado = code(dict, text);
    codeSize = strlen(codificado);

    fprintf(codedFile, "%d\n", codeSize);

    while (codeSize % 8 != 0)
    {
        strcat(codificado, "0");
        codeSize++;
    }
    fprintf(auxFile, "%s", codificado);
    fclose(auxFile);

    fprintf(codedFile, "%d\n", tableSize);
    for (i = 0; i < SIZE; i++)
    {
        if (frequencyTable[i] > 0)
        {
            fprintf(codedFile, "%d %d\n", i, frequencyTable[i]);
        }
    }

    auxFile = fopen("aux.txt", "r");
    while (!feof(auxFile))
    {
        fscanf(auxFile, "%c", &vet[0]);
        fscanf(auxFile, "%c", &vet[1]);
        fscanf(auxFile, "%c", &vet[2]);
        fscanf(auxFile, "%c", &vet[3]);
        fscanf(auxFile, "%c", &vet[4]);
        fscanf(auxFile, "%c", &vet[5]);
        fscanf(auxFile, "%c", &vet[6]);
        fscanf(auxFile, "%c", &vet[7]);
        carac = convert_byte(vet, 8);
        fprintf(codedFile, "%c", carac);
    }

    fseek(arquivo, 0, SEEK_END);
    fseek(codedFile, 0, SEEK_END);

    long economia = ftell(arquivo) - ftell(codedFile);

    fclose(auxFile);
    fclose(codedFile);
    fclose(arquivo);

    remove("aux.txt");

    printf("\n\t\tCOMPRESSÃO REALIZADA.\n\n");

    printf("\n\t\tECONOMIA: %ld bytes\n\n", economia);
}
void decompress(unsigned int frequencyTable[], char file[])
{
    FILE *codedFile = fopen(file, "r");
    FILE *auxFile = fopen("aux.txt", "w+");
    FILE *arquivo = fopen("decompressedFile.txt", "w");

    if (!arquivo || !auxFile || !codedFile)
    {
        printf("\nErro ao abrir o arquivo.");
        return;
    }

    List list;
    Node *tree;

    int n, i, aux, col, bitsN;
    char vet[8], ch, **dict, *decoded, text[1000000];

    fscanf(codedFile, "%d", &bitsN);
    fscanf(codedFile, "%d", &n);

    for (i = 0; i < SIZE; i++)
    {
        frequencyTable[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        fscanf(codedFile, "%d", &aux);
        fscanf(codedFile, "%d", &frequencyTable[aux]);
    }

    init_list(&list);
    fill_list(frequencyTable, &list);

    tree = init_tree(&list);
    col = tree_height(tree) + 1;
    dict = dictionary_allocation(col);

    init_dictionary(dict, tree, "", col);

    while (!feof(codedFile))
    {
        fscanf(codedFile, "%c", &ch);
        convert(ch, vet);
        fprintf(auxFile, "%s", vet);
    }

    fseek(auxFile, 0, SEEK_SET);
    fgets(text, bitsN, auxFile);
    decoded = decode(text, tree);
    fprintf(arquivo, "%s", decoded);

    fseek(arquivo, 0, SEEK_END);
    fseek(codedFile, 0, SEEK_END);
    long economia = ftell(arquivo) - ftell(codedFile);

    printf("\n\t\tDESCOMPRESSÃO REALIZADA.\n");

    printf("\n\t\tDIFERENÇA: %ld bytes\n", economia);

    fclose(arquivo);
    fclose(auxFile);
    fclose(codedFile);

    remove("aux.txt");
}
/*
================================================================
Funções auxiliares - conversão e strings
================================================================
*/
int string_size(char **dict, unsigned char *text)
{
    int i = 0, size = 0;
    while (text[i] != '\0')
    {
        size = size + strlen(dict[text[i]]);
        i++;
    }
    return size + 1;
}
unsigned char convert_byte(char *vet, int n)
{
    unsigned char rtno = 0, i = 0;
    int j = 0;

    while (i < n)
    {
        rtno += pow(2, i) * (vet[(n - 1) - i] - 48);
        i++;
    }

    return rtno;
}
void convert(char ch, char *vet)
{
    int i = 7;

    while (i >= 0)
    {
        if (ch & 1)
            vet[i] = '1';
        else
            vet[i] = '0';

        i--;
        ch >>= 1;
    }
}
