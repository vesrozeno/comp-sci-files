#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//Tamanho da matriz de conexoes e vetor de distancias
#define N 5

//PROGRAMA PRINCIPAL
//MATRIZ A: representa as conexoes entre as cidades 0,..,N-1
//VETOR DIST: dist[i] eh a distancia da cidade 'c' até 'i'
int main(int argc, char *argv[]) {
	//Inicializacao da matriz de cidades
	int A[N][N] = 
	{
		{0,1,0,0,0},
		{0,0,1,0,0},
		{0,0,0,0,1},
		{0,0,1,0,1},
		{0,1,0,0,0}
	};
	
	int dist[N];
	int i,j,c=2;	
	fila F;
	for(i=0;i<N;i++)
	{
		dist[i] = N; //Seta dist[j] = inf, para todo i
	}
	dist[c] = 0;
	Definir(&F); //Cria fila vazia
	Inserir(&F,c); //Insere a cidade 'c' na fila
	
	//Roda até que todos os nos tenham sido checados
	//Tira da fila uma cidade i, e coloca na fila
	//as cidade vizinhas j com distancia nao computadas
	while(!Vazia(&F))
	{
		Remover(&F,&i);
		for(j=0; j<N; j++)
		{
			if(A[i][j]==1 && dist[j] >= N)
			{
				dist[j] = dist[i] + 1;
				Inserir(&F, j);
			}
		}
	}
	
	//Imprime o vetor distancias de c para as cidades i
	for(i=0;i<N;i++)
	{
		printf("dist[%d]: %d\n",i,dist[i]);
	}
	return 0;
}
