// Vitor Emanuel da Silva Rozeno  - RA: 211044539
// Projeto 3 - balanca.c
#include <stdio.h>

// Protóripos das Funções que serão usadas.
int validaNM(int, int);
void leituraPesoProduto(int, int *, int, int *);
void ordenaCresc(int *, int);
void ordenaDecresc(int *, int);
void zeraVetor(int *, int);
void printaVetor(int *, int);
int balanca(int, int *, int, int *, int);

// Função Principal.
int main()
{
    int n = 0, m = 0, peso[20], i, produto[100], resultado[20];

    // Entrada de Dados - N e M
    printf("\nDigite a qtd de produtos e pesos: ");

    // Estrutura de repetição para validar os valores (utilizando a função "validaNM").
    do
    {
        scanf("%d %d", &n, &m);
    } while (validaNM(n, m));

    // Entrada de Dados - Pesos e Produtos (utilizando a função "leituraPesoProduto").
    leituraPesoProduto(m, peso, n, produto);

    // Chamada da função para ordenar o vetor "peso" em ordem crescente.
    ordenaCresc(peso, m);

    printf("\n\n");

    // Saída de dados - seguindo a quantidade "n" de produtos
    // e encontrando os pesos adequados pela chamada da função "balanca" que atuará recursivamente.
    for (i = 0; i < n; i++)
    {
        // Chamada de função para zerar o vetor 'resultado' a cada for.
        zeraVetor(resultado, m);

        // Se forem encontrados os pesos adqueados, a função irá atribuí-los ao vetor de resultado
        // e o laço partirá para o próximo produto.
        if (balanca(produto[i], peso, m - 1, resultado, 1))
        {
            // Chamada de função para ordenar o vetor 'resultado' em ordem descrescente.
            ordenaDecresc(resultado, m);
            // Chamada de função para printar os valores contidos no vetor 'resultado'.
            printaVetor(resultado, m);
            printf("\n");
        }
        // Se a função "balanca" não encontrar pesos adequados, será printado um "0".
        else
        {
            printf("0\n");
        }
    }

    return 0;
}
// Função para validar os valores "n" e "m" inseridos.
int validaNM(int n, int m)
{
    // N deve ser maior ou igual a 1 e menor ou igual a 100;
    // M deve ser maior ou igual a 5 e menor ou igual a 20.
    if (n >= 1 && n <= 100 && m >= 5 && m <= 20)
    {
        return 0;
    }
    // Mensagem de retorno, caso os valores sejam inválidos.
    else
    {
        printf("\nValor inválido inserido. Tente novamente...\n\nInsira os valores: ");
        return 1;
    }
}
// Função para a leitura dos valores de pesos e produtos.
void leituraPesoProduto(int m, int *peso, int n, int *produto)
{
    int i;
    printf("\n\nDigite os valores dos pesos: ");

    // Laço seguindo a quantidade "m" de pesos.
    for (i = 0; i < m; i++)
    {
        scanf(" %d", &peso[i]); // Valores de peso inseridos irão para o vetor "peso".
    }

    printf("\n\nDigite os valores dos produtos:\n");

    // Laço seguindo a quantidade "n" de produtos.
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &produto[i]); // Valores de produto inseridos irão para o vetor "produto".
    }
}
// Função para ordenar vetor em ordem Crescente.
void ordenaCresc(int *vetor, int qtd)
{
    int i, aux, ultimo;

    // Laço contendo um laço para que o vetor seja percorrido
    // a quantidade de vezes necessárias para que esteja
    // totalmente em ordem crescente.
    for (ultimo = qtd - 1; ultimo >= 0; ultimo--)
    {
        for (i = 0; i < ultimo; i++)
        {
            // Condicional para verificar se a posição atual
            //é maior que a posição posterior.
            if ((vetor[i] > vetor[i + 1]))
            {
                // Se sim, as posições serão trocadas.
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
}
// Função para ordenar vetor em ordem Decrescente.
void ordenaDecresc(int *vetor, int qtd)
{
    int i, aux, ultimo;

    // Laço contendo um laço para que o vetor seja percorrido
    // a quantidade de vezes necessárias para que esteja
    // totalmente em ordem decrescente.
    for (ultimo = qtd - 1; ultimo >= 0; ultimo--)
    {
        for (i = 0; i < ultimo; i++)
        {
            // Condicional para verificar se a posição atual
            //é menor que a posição posterior.
            if ((vetor[i] < vetor[i + 1]))
            {
                // Se sim, as posições serão trocadas.
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
}
// Função para zerar vetor.
void zeraVetor(int *vetor, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        vetor[i] = 0;
    }
}
// Função para printar os valores contidos em um vetor.
void printaVetor(int *vetor, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        // Nesse caso, por se tratar de um vetor zerado,
        // serão printados os valores que forem diferentes de zero.
        if (vetor[i] != 0)
        {
            printf("%d ", vetor[i]);
        }
    }
}
// Função para encontrar os pesos adequados para balancear com os produtos.
int balanca(int produto, int *peso, int m, int *resultado, int inverter)
{
    // Se o produto for igual a 0, significa que é possível balanceá-lo,
    // portanto retorna-se 1 (verdadeiro).
    if (produto == 0)
    {
        return 1;
    }
    // Se a quantidade de pesos ou o produto for menor que 0,
    // quer dizer que os pesos não foram suficientes;
    // Retorna-se 0 (falso);
    if (m < 0 || produto < 0)
    {
        return 0;
    }
    // Recursão - chama-se a função e assume "produto" como sendo "produto - peso" no índice "m",
    // sendo este agora, "m-1".
    // Ou seja, testa-se todos os pesos, do maior ao menor, subtraindo do produto.
    // Ao final, se encontrar os devidos pesos, a função "voltará em suas chamadas",
    // retornando 1 e atribuindo ao vetor 'resultado' os pesos que sucederam.
    if (balanca(produto - peso[m], peso, m - 1, resultado, inverter))
    {
        resultado[m] = peso[m] * inverter;
        return 1;
    }
    // Caso não retorne 1, testa-se o produto atual com um índice a menos em peso[m],
    // se suceder, ele chegará ao if acima e será atribuído ao vetor.
    else if (balanca(produto, peso, m - 1, resultado, inverter))
    {
        return 1;
    }
    // Caso não suceda, ainda se testa o valor da subtração do produto e o peso atual,
    // se for menor que zero e a subtração inversa (peso atual - produto) suceder aos testes,
    // o peso será atribuído ao vetor, implicando que os seguintes testes estarão "invertidos",
    // por isso, se ao fim sucederem, serão multiplicados por -1,
    // pois estarão "no plato dos produtos" para serem balanceados.
    else if ((produto - peso[m] < 0) && balanca(peso[m] - produto, peso, m - 1, resultado, -inverter))
    {
        resultado[m] = peso[m] * inverter;
        return 1;
    }
    // Se ao final o produto não suceder em ser balanceado,
    // será retornado 0 (falso) e um 0 será printado.
    return 0;
}
