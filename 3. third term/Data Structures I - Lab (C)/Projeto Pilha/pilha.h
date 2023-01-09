#dfine MAX 1000 // estimativa de tamanha maximo
#define TRUE 1
#define FALSE 0
#define boolean int
# define indice int


//Estruturas e tipos empregados

//-----------------------------------------------------------
//Tipo chave
typedef int tipo_chave;

//Tipo registro
typedef struct
{
	char nome[30];
	//.... caso tenha mais campos
}tipo_dado;

//Tipo elemento(registro + chave)
typedef struct
{
	tipo_chave chave;
	tipo_dado info;
}tipo_elem;

//Tipo pilha (sequencial)
typedef struct
{
	tipo_elem A[MAX+1];
	indice topo;
}pilha;
