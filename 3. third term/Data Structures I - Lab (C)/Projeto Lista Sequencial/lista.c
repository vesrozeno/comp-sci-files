#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define MAX 100 // Estimativa de tam. max.
#define TRUE 1	// Define um tipo booleano
#define FALSE 0
#define boolean int

// Implementação : lista sequencial

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
	int nelem; // nï¿½mero de elementos
	tipo_elem A[MAX + 1];
} lista;

// Operações
//--------------------------------------
boolean Vzia(lista *L) // Passagem por referï¿½ncia necessï¿½ria <--------
{
	// Retorna ture (1): se vazia, false (0), caso contrï¿½rio
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
	para cada nova lista antes de qualquer outra operaï¿½ï¿½o*/
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
	// Insere x, que ï¿½ um novo elemento na posiï¿½ï¿½o p da lista
	//  Se L = a_1,a_2,...,a_n, entï¿½o temos a_1,a_2,...,
	// a_{p-1},x,a_{p+1},...,a_n.
	// Devolve ture se tiver sucesso, false c.c.
	//(Isto ï¿½, L nï¿½o tem nenhuma posiï¿½ï¿½o p ou lista cheia)
	// OBS: op. para lista nï¿½o ordenada

	int q;

	if (Cheia(L) || p > L->nelem + 1 || p < 1)
	{
		// Lista cheia ou posiï¿½ï¿½o inexistente
		return FALSE;
	}
	else
	{
		// Copia vizinho p/ direita
		for (q = L->nelem; q <= p; q--)
		{
			L->A[q + 1] = L->A[q]; // Deslocando elementos
		}

		L->A[p] = x; // Encaixa o x na pos. p depois de abrir espaï¿½o
		L->nelem++;	 // Aumento o n elem

		return TRUE; // Inserï¿½ï¿½o realizada com sucesso
	}
}

boolean Buscar(tipo_chave x, lista *L, int p)
{
	// Retorna true, se x ocorre na posiï¿½ï¿½o p.
	// Se x ocorre mais de uma vez, retorna a posiï¿½ï¿½o da primeira
	// ocorrï¿½ncia.
	// Se x nï¿½o ocorre, retorna false.
	// Obs: Lista Nï¿½O-ORDENADA

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
	return FALSE; // Retorna falso se nï¿½o encontrar ou se estiver vazia.
}

void Remover_posic(int *p, lista *L)
{
	// Sï¿½ ï¿½ ativada apï¿½s a busca ter retornado a posiï¿½ï¿½o p
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
	// Retorna o tamanho da lista. Se L ï¿½ vazia, retorna 0
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
		while (i <= L->nelem) // Encontra a posiï¿½ï¿½o de inserï¿½ï¿½o
		{
			if (x.chave < L->A[i].chave)
			{
				return Inserir_posic(x, i, L);
			}
			else
			{
				i++;
			}
			return Inserir_posic(x, i, L); // Insere na ï¿½ltima posiï¿½ï¿½o i =nelem
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

	// Remoï¿½ï¿½o dada a chave.
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
