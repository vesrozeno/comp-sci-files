//TAD: matriz real m x n

//Tipo exportado
typedef struct matriz Matriz;
 
// Fun��es exportadas
//---------------------------------------------------------------------
//Fun��o cria: aloca e retorna matriz m x n
Matriz *cria(int m, int n);

//Fun��o libera: libera a mem�ria de uma matriz
void libera(Matriz *mat);

//Fun��o acessa; retorna o valor do elemento [i][j]
float acessa(Matriz *mat, int i, int j);

//Fun��o atribui: atribui valor ao elemento [i][j]
void atribui(Matriz *mat, int i, int j, float v);

//Fun��o linhas: retorna n�mero de linhas da matriz
int linhas(Matriz *mat);

//Fun��o colunas: retorna n�mero de colunas matriz
int colunas(Matriz *mat);

