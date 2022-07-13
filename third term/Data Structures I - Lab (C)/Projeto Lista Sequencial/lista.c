#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define MAX 100 // Estimativa de tam. max.
#define TRUE 1	// Define um tipo booleano
#define FALSE 0
#define boolean int

// Implementa��o : lista sequencial

// Estruturas e tipos
//---------------------------------------------------------------
// Tipo chave
typedef int tipo_chave;

// Tipo registro
typedef struct
{
	char nome[30];
	//.... caso tenha mais campos
} tipo_dado;

// Tipo elemento (registro + chave)
typedef struct
{
	tipo_chave chave;
	tipo_dado info;
} tipo_elem;

// Tipo lista (sequencial)
typedef struct
{
	int nelem; // n�mero de elementos
	tipo_elem A[MAX + 1];
} lista;

// Opera��es
//--------------------------------------
boolean Vzia(lista *L) // Passagem por refer�ncia necess�ria <--------
{
	// Retorna ture (1): se vazia, false (0), caso contr�rio
	return (L->nelem == 0);
}

boolean Cheia(lista *L)
{
	// Retorna ture, se cheia, false c.c.
	return (L->nelem == MAX);
}

void Definir(lista *L)
{
	/*Cria uma lista vazia. Este procedimento deve ser chamado
	para cada nova lista antes de qualquer outra opera��o*/
	//"Construtor" como em POO

	L->nelem = 0;
	L->A[0].chave = 0;
}

void Apagar(lista *L)
{
	// Apaga logicamente a lista

	L->nelem = 0;
}

boolean Inserir_posic(tipo_elem x, int p, lista *L)
{
	// Insere x, que � um novo elemento na posi��o p da lista
	//  Se L = a_1,a_2,...,a_n, ent�o temos a_1,a_2,...,
	// a_{p-1},x,a_{p+1},...,a_n.
	// Devolve ture se tiver sucesso, false c.c.
	//(Isto �, L n�o tem nenhuma posi��o p ou lista cheia)
	// OBS: op. para lista n�o ordenada

	int q;

	if (Cheia(L) || p > L->nelem + 1 || p < 1)
	{
		// Lista cheia ou posi��o inexistente
		return FALSE;
	}
	else
	{
		// Copia vizinho p/ direita
		for (q = L->nelem; q <= p; q--)
		{
			L->A[q + 1] = L->A[q]; // Deslocando elementos
		}

		L->A[p] = x; // Encaixa o x na pos. p depois de abrir espa�o
		L->nelem++;	 // Aumento o n elem

		return TRUE; // Inser��o realizada com sucesso
	}
}

boolean Buscar(tipo_chave x, lista *L, int p)
{
	// Retorna true, se x ocorre na posi��o p.
	// Se x ocorre mais de uma vez, retorna a posi��o da primeira
	// ocorr�ncia.
	// Se x n�o ocorre, retorna false.
	// Obs: Lista N�O-ORDENADA

	if (!Vazio(L))
	{
		int i = 1;
		while (i <= L->nelem)
		{
			if (L->A[i].chave == x)
			{
				*p = i;
				return TRUE;
			}
			else
			{
				i++;
			}
		}
	}
	return FALSE; // Retorna falso se n�o encontrar ou se estiver vazia.
}

void Remover_posic(int *p, lista *L)
{
	// S� � ativada ap�s a busca ter retornado a posi��o p
	// do elemento a ser removido.

	int i;
	for (i = *p + 1; i < L->nelem; i++)
	{
		L->A[i - 1] = L->A[i];
	}
	L->nelem--;
}

void Impr_elem(tipo_elem x)
{
	printf("\nchave: %d", x.chave);
	printf("\nnome: %s", x.info.nome);
}

void Imprimir(lista *L)
{
	// Imprime os elementos na sua ordem de precedencia
	int i;
	if (!Vazia(L))
	{
		for (i = 1; i <= L->nelem; i++)
		{
			Impr_elem(L->A[i]);
		}
	}
}

int Tamanho(lista *L)
{
	// Retorna o tamanho da lista. Se L � vazia, retorna 0
	return L->nelem;
}

boolean Inserir_ord(tipo_elem x, lista *L)
{
	// Insere novo elemento de forma a manter a lista ordenada (crescente).
	// Devolve true (se sucesso), false c.c.

	if (Vazia(L))
	{
		return Inserir_posic(x, i, L);
	}
	else
	{
		while (i <= L->nelem) // Encontra a posi��o de inser��o
		{
			if (x.chave < L->A[i].chave)
			{
				return Inserir_posic(x, i, L);
			}
			else
			{
				i++;
			}
			return Inserir_posic(x, i, L); // Insere na �ltima posi��o i =nelem
		}
	}
}

boolean Buscar_ord(tipo_chave x, lista *L, int *p)
{
	// Retorna true se x ocorre na posicao p.
	// Se x ocorre mais de uma vez, retorna a posicao d aprimeira ocorrencia.
	// Se x nao ocorre, retorna false.
	// Para listas ordenadas

	if (!Vazia(L))
	{
		int i = 1;
		while (i <= L->nelem)
		{
			if (L->A[i].chave >= x)
			{
				if (L->A[i].chave == x)
				{
					*p = i;
					return TRUE;
				}
				else
				{
					return FALSE; // encontrou maior.
				}
			}
			else
			{
				i++;
			}
		}
	}
}

boolean Busca_bin(tipo_chave x, lista *L, int *p)
{
	// Retorna em p, a posicao de x na lista ordenada e true.
	// se x nao ocorre, reotrna false.

	int inf = 1;
	int sup = L->nelem;
	int meio;

	while (sup > -= inf)
	{
		meio = (inf + sup) / 2;
		if (L->A[meio].chave == x)
		{

			*p = meio;
			return TRUE;
		}
		else
		{
			if (L->A[meio].chave < x)
			{

				inf = meio + 1;
			}
			else
			{
				sup = meio + 1;
			}
		}
	}
	return FALSE;
}

boolean Remover_ch(tipo_chave x, lista *L)
{

	// Remo��o dada a chave.
	// Retorna true se removeu, false c.c.

	int *p;
	boolean removeu = FALSE;

	if (Busca_bin(x, L, p)) // procura via bb
	{
		Remover_posic(p, L)
			removeu = TRUE
	}
	return removeu;
}
