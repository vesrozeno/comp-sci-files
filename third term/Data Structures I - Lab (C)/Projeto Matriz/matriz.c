#include <stdlib.h>//Para malloc, free, exit...
#include <stdio.h>//Para printf, scanf...
#include "matriz.h"//Carrega arquivo .h criado

//Implementa��o da struct matriz
struct matriz
{
	int lin, col;
	float *v;
};

//Implementa��o das fun��es do TAD matriz
//----------------------------------------------------------------
void libera(Matriz *mat)
{
	free(mat->v);
	free(mat);
}

Matriz *cria(int m, int n)
{
	Matriz *mat = (Matriz*) malloc(sizeof(Matriz));
	
	if(mat == NULL)
	{
		printf("Mem�ria insuficiente.\n");
		exit(1);
	}
	
	mat->lin = m;
	mat->col = n;
	mat->v = (float*) malloc(m*n*sizeof(float));
	return mat;
}

float acessa(Matriz *mat, int i, int j)
{
	int k;
	if(i < 0 || i >= mat->lin || j < 0 || j >= mat->col)
	{
		printf("Acesso Inv�lido\n");
		exit(1);
	}
	
	k = i * mat->col + j;//Convers�o ind�ce duplo p/ simples
	return mat->v[k];
}

void atribui(Matriz *mat, int i, int j, float v)
{
	int k;
	if(i < 0 || i >= mat->lin || j < 0 || j >= mat->col)
	{
		printf("Acesso Inv�lido\n");
		exit(1);
	}
	k = i * mat->col + j;
	mat->v[k]=v;	
}

int linhas(Matriz *mat)
{
	return mat->lin;
}

int colunas(Matriz *mat)
{
	return mat->col;
}


























