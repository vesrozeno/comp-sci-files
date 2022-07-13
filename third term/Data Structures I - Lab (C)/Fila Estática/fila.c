#include "fila.h"

//Cria fila vazia
void Definir(fila *q)
{
	q->inicio = 0;
	q->fim = 0;
}

//Verifica se a fila esta vazia
boolean Vazia(fila *q)
{
	return(q->inicio == q->fim);
}

//Verifica se fila esta cheia
boolean Cheia(fila *q)
{
	return(q->inicio==((q->fim+1)% tam_fila));
	//Obs: os dois ponteiros diferem de uma posição
}
//Adiciona um elemento no fim da fila
boolean Inserir(fila *q, int elem)
{
	if(Cheia(q))
	{
		return FALSE;
	}
	
	q->fim = (q->fim + 1) % tam_fila;
	q->A[q->fim] = elem;
	return TRUE;
}
//Remove um elemento do inicio da fila
boolean Remover(fila *q, int *elem)
{
	if(Vazia(q))
	{
		return FALSE;
	}
	
	q->inicio = (q->inicio + 1) % tam_fila;
	*elem = q->A[q->inicio];
	return TRUE;
}

//Retorna o tamanho da fila
int Tamanho(fila *q)
{
	if(q->inicio <= q->fim)
	{
		return (q->fim - q->inicio);
	}
	
	return(tam_fila - (q->inicio - q->fim));
}
//Mostra o comeco da fila sem remover o elemento
boolean Inicio_fila(fila *q, int elem)
{
	if(Vazia(q))
	{
		return FALSE;
	}
	elem = q->A[(q->inicio+1) % tam_fila];
	return TRUE;
}
