//TAD: matriz real m x n

//Tipo exportado
typedef struct matriz Matriz;
 
// Funções exportadas
//---------------------------------------------------------------------
//Função cria: aloca e retorna matriz m x n
Matriz *cria(int m, int n);

//Função libera: libera a memória de uma matriz
void libera(Matriz *mat);

//Função acessa; retorna o valor do elemento [i][j]
float acessa(Matriz *mat, int i, int j);

//Função atribui: atribui valor ao elemento [i][j]
void atribui(Matriz *mat, int i, int j, float v);

//Função linhas: retorna número de linhas da matriz
int linhas(Matriz *mat);

//Função colunas: retorna número de colunas matriz
int colunas(Matriz *mat);

