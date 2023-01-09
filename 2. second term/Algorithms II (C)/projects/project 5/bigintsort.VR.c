// Projeto 5 - Ordenação - Vitor Emanuel da Silva Rozeno RA: 211044539 - bigintsort.VR.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Definir constante.
#define N_NUMEROS 200000

// Structs.
struct timeval fim, comeco;
typedef struct biggo
{
    int high;
    int low;
} BigInt;

// Protótipos das funções usadas.
void lerArquivo(FILE *file, BigInt *vetorBigInt);
void testaArquivo(FILE *file);
void resetaVetor(BigInt *defaultBigInt, BigInt *vetorBigInt);
int funcPow(int a, int b);
void shellSort(BigInt *vetorBigInt);
void selectionSort(BigInt *vetorBigInt);
void escreveArquivo(FILE *file, BigInt *vetorBigInt);
// Função principal.
int main()
{
    // Abrir bigint.dat
    FILE *bigIntFile = fopen("bigint.dat", "r");
    testaArquivo(bigIntFile);

    BigInt defaultBigInt[N_NUMEROS], vetorBigInt[N_NUMEROS];

    // Lê BigInt.dat, dados vão para defaultBigInt
    lerArquivo(bigIntFile, defaultBigInt);
    fclose(bigIntFile);

    //============ CHAMADA SHELL SORT============================

    // Inicializa vetor com valores lidos em BigInt
    resetaVetor(defaultBigInt, vetorBigInt);
    FILE *shellFile = fopen("shell.dat", "w");
    testaArquivo(shellFile);
    // Funções da biblioteca sys/time.h para calcular tempo de execução.
    gettimeofday(&comeco, NULL);
    shellSort(vetorBigInt);
    gettimeofday(&fim, NULL);

    printf("\nShell Sort - Tempo de Execução: %lf segundos\n", (double)(fim.tv_sec - comeco.tv_sec + 1E-6 * (fim.tv_usec - comeco.tv_usec)));
    escreveArquivo(shellFile, vetorBigInt);
    fclose(shellFile);

    //=============== CHAMADA SELECTION SORT=======================

    // Reinicializa vetor com valores lidos em BigInt.
    resetaVetor(defaultBigInt, vetorBigInt);
    // Inicializa arquivo Selection.
    FILE *selectionFile = fopen("selection.dat", "w");
    testaArquivo(selectionFile);
    // Funções da biblioteca sys/time.h para calcular tempo de execução.
    gettimeofday(&comeco, NULL);
    selectionSort(vetorBigInt);
    gettimeofday(&fim, NULL);

    printf("\nSelection Sort - Tempo de Execução: %lf segundos\n", (double)(fim.tv_sec - comeco.tv_sec + 1E-6 * (fim.tv_usec - comeco.tv_usec)));
    escreveArquivo(selectionFile, vetorBigInt);
    fclose(selectionFile);

    printf("\n");

    return 0;
}
// Função para ler arquivo.
void lerArquivo(FILE *file, BigInt *vetorBigInt)
{
    int i;
    for (i = 0; i < N_NUMEROS; i++)
    {
        fscanf(file, "%d %d", &vetorBigInt[i].high, &vetorBigInt[i].low);
    }
}
// Função para testar se alocação de memória deu certo.
void testaArquivo(FILE *file)
{
    if (file == NULL)
    {
        printf("\nEncerrando. Erro ao alocar memória.\n\n");
        exit(1);
    }
}
// Função para resetar valores do vetor com dados BigInt.
void resetaVetor(BigInt *defaultBigInt, BigInt *vetorBigInt)
{
    for (int i = 0; i < N_NUMEROS; i++)
    {
        vetorBigInt[i].high = defaultBigInt[i].high;
        vetorBigInt[i].low = defaultBigInt[i].low;
    }
}
// Função para potenciação.
int funcPow(int a, int b)
{
    int i, pow = a;

    if (a == 0)
    {
        return 0;
    }
    if (b == 0)
    {
        return 1;
    }
    for (i = 1; i < b; i++)
    {
        pow *= a;
    }
    return pow;
}
// Função método de ordenação shell sort.
void shellSort(BigInt *vetorBigInt)
{
    int i, j, p, k[10] = {1, 0}, l;
    BigInt auxInsert;
    p = 1;
    while (k[p - 1] < N_NUMEROS / 2)
    {
        k[p] = funcPow(4, p) + 3 * funcPow(2, p - 1) + 1;
        p++;
    }
    p--;
    while (p > 0)
    {
        p--;
        for (l = 0; l < k[p]; l++)
        {
            for (i = l + k[p]; i < N_NUMEROS; i += k[p])
            {
                auxInsert = vetorBigInt[i];
                j = i;

                while (j - k[p] >= 0 && vetorBigInt[j - k[p]].high >= auxInsert.high)
                {
                    if ((vetorBigInt[j - k[p]].high > auxInsert.high) || (vetorBigInt[j - k[p]].high >= 0 && vetorBigInt[j - k[p]].low > auxInsert.low) || (vetorBigInt[j - k[p]].high < 0 && vetorBigInt[j - k[p]].low < auxInsert.low))
                    {
                        vetorBigInt[j] = vetorBigInt[j - k[p]];
                        j = j - k[p];
                    }
                    else
                        break;
                }

                if (j != i)
                {
                    vetorBigInt[j] = auxInsert;
                }
            }
        }
    }
}
// Função método de ordenação selection sort.
void selectionSort(BigInt *vetorBigInt)
{
    int i, j, minIdx;

    for (i = 0; i < N_NUMEROS; i++)
    {
        minIdx = i;
        for (j = i + 1; j < N_NUMEROS; j++)
        {
            if (vetorBigInt[minIdx].high >= vetorBigInt[j].high)
            {
                if ((vetorBigInt[minIdx].high > vetorBigInt[j].high) || (vetorBigInt[minIdx].high >= 0 && vetorBigInt[minIdx].low > vetorBigInt[j].low) || (vetorBigInt[minIdx].high < 0 && vetorBigInt[minIdx].low < vetorBigInt[j].low))
                {
                    minIdx = j;
                }
            }
        }

        if (minIdx != i)
        {
            BigInt aux = vetorBigInt[minIdx];
            vetorBigInt[minIdx] = vetorBigInt[i];
            vetorBigInt[i] = aux;
        }
    }
}
// Função para escrever em arquivo.
void escreveArquivo(FILE *file, BigInt *vetorBigInt)
{
    int i;
    for (i = 0; i < N_NUMEROS; i++)
    {
        fprintf(file, "%d %d\n", vetorBigInt[i].high, vetorBigInt[i].low);
    }
}
