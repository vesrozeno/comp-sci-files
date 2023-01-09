#define TRUE 1
#define FALSE 0
#define boolean int //Tipo booleano
#define tam_fila 100 //Tamanho maximo da fila
#define indice int //Tipo indice


//Estruturas
//--------------------------------------------------------------------
typedef struct
{
	int A[tam_fila];
	indice inicio, fim;	
}fila;

//Declaracao das operacoes
//--------------------------------------------------------------------
//Cria fila vazia
void Definir(fila *q);
//Verifica se a fila esta vazia
boolean Vazia(fila *q);
//Verifica se fila esta cheia
boolean Cheia(fila *q);
//Adiciona um elemento no fim da fila
boolean Inserir(fila *q, int elem);
//Remove um elemento do inicio da fila
boolean Remover(fila *q, int *elem);
//Retorna o tamanho da fila
int Tamanho(fila *q);
//Mostra o comeco da fila sem remover o elemento
boolean Inicio_fila(fila *q, int elem);
