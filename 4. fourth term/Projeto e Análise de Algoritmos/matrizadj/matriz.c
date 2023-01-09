/*

Vitor Emanuel da Silva Rozeno
211044539

*/

#include <stdio.h>

int vertex = 0;

void initMatrix(int matrix[][vertex]);
void addVertex(int matrix[][vertex], int i, int j);
void printMatrix(int matrix[][vertex]);
void simplePrint(int matrix[][vertex]);

int main()
{
    int node1 = 0, node2 = 0, verify = 1;

    printf("\n\tQuantidade de vértices: ");
    scanf("%d", &vertex);
    int matrix[vertex][vertex];
    initMatrix(matrix);
    simplePrint(matrix);
    while (verify != 0)
    {
        printf("\n\t2 nós adjacentes: ");

        scanf("%d", &node1);
        scanf("%d", &node2);

        addVertex(matrix, node1, node2);

        printf("\n\t(0) Sair e Printar Matrix\n\t(!=0) Continuar\n\t-----> ");

        scanf("%d", &verify);
    }
    simplePrint(matrix);
    printf("\n");
    printMatrix(matrix);
    return 0;
}

void initMatrix(int matrix[][vertex])
{
    int i, j;
    for (i = 0; i < vertex; i++)
    {
        for (j = 0; j < vertex; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void addVertex(int matrix[][vertex], int i, int j)
{
    matrix[i][j] = 1;
    matrix[j][i] = 1;
}

void printMatrix(int matrix[][vertex])
{
    int i, j;
    for (i = 0; i < vertex; i++)
    {
        printf("%d - ", i);
        for (j = 0; j < vertex; j++)
        {
            if (matrix[i][j] == 1)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

void simplePrint(int matrix[][vertex])
{
    int i = 0, j = 0;
    for (i = 0; i < vertex; i++)
    {
        for (j = 0; j < vertex; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}