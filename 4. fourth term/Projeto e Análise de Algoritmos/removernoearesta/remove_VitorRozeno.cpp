// Vitor Emanuel da Silva Rozeno - RA: 211044539
// Atividade PAA - Remoção de arestas e nós

#include <iostream>
#include <vector>

void insert(std::vector<std::vector<int>> &matrix, int v1, int v2);
void print(std::vector<std::vector<int>> matrix, int size);
void edge_remove(std::vector<std::vector<int>> &matrix, int v1, int v2);
void node_remove(std::vector<std::vector<int>> &matrix, int v, int size);

int main()
{
    int size, v1, v2;
    std::vector<std::vector<int>> matrix;

    do
    {
        std::cout << "\nmatrix size: ";
        std::cin >> size;
    } while (size <= 0);

    matrix.resize(size);

    for (auto &line : matrix)
    {
        line.resize(size);
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = 0;
        }
    }

    int menu = 0;
    do
    {
        std::cout << "\n1) insert\n2) print\n3) remove edge\n4) remove node\n5) exit\n\n--->";
        std::cin >> menu;

        switch (menu)
        {

        case 1:

            do
            {
                std::cout << "\nInsert\nwhich nodes?\n--->";
                std::cin >> v1;
                std::cin >> v2;
            } while (v1 == v2 || v1 > size || v2 > size || v1 < 1 || v2 < 1);
            v1--;
            v2--;

            insert(matrix, v1, v2);
            break;

        case 2:
            print(matrix, size);
            break;

        case 3:
            std::cout << "\nRemove Edge\nwhich edge?\n--->";
            std::cin >> v1;
            std::cin >> v2;

            v1--;
            v2--;

            edge_remove(matrix, v1, v2);
            break;

        case 4:
            std::cout << "\nRemove node\nwhich node?\n--->";
            std::cin >> v1;

            v1--;
            v2--;

            node_remove(matrix, v1, size);
        case 5:
            break;

        default:
            std::cout << "\nerror - try again\n";
        }

    } while (menu != 5);
    return 0;
}
void insert(std::vector<std::vector<int>> &matrix, int v1, int v2)
{
    if (matrix[v1][v2] == -1)
    {
        std::cout << "\n\terror - no node\n";
        return;
    }

    if (matrix[v1][v2] == 1)
    {
        std::cout << "\n\terror\n";
        return;
    }
    matrix[v1][v2] = 1;
    matrix[v2][v1] = 1;
    std::cout << "\n\tsuccess\n";
}

void print(std::vector<std::vector<int>> matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (matrix[i][0] != -1)
        {
            std::cout << i + 1;
        }
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] == 1)
            {
                std::cout << " -> " << j + 1;
            }
        }
        if (matrix[i][0] != -1)
        {
            std::cout << "\n";
        }
    }
}

void edge_remove(std::vector<std::vector<int>> &matrix, int v1, int v2)
{
    if (matrix[v1][v2] == 0)
    {
        std::cout << "\n\terror - no edge";
        return;
    }

    if (matrix[v1][v2] == -1)
    {
        std::cout << "\n\terror - no node";
        return;
    }
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
    std::cout << "\n\tsuccess\n";
}

void node_remove(std::vector<std::vector<int>> &matrix, int v, int size)
{
    int i, j;

    if (matrix[v][v] == -1)
    {
        std::cout << "\n\terror - no node";
        return;
    }

    for (i = 0; i < size; i++)
    {
        matrix[v][i] = -1;
        matrix[i][v] = -1;
    }
    std::cout << "\n\tsuccess.\n";
}
