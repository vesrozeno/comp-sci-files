#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(int argc, char *argv[]) 
{
	float a,b,c;
	Matriz *M;
	
	//Criar uma matriz 5x5
	M = cria(5,5);
	
	//Insere valores na matriz
	atribui(M,1,2,10);
	atribui(M,2,3,20);
	atribui(M,3,0,11);
	
	//Verifica se a inserção foi feita corretamente 
	a = acessa(M,1,2);
	b = acessa(M,2,3);
	c = acessa(M,3,0);
	
	printf("M[1][2]: %.2f\n",a); 
	printf("M[2][3]: %.2f\n",b); 
	printf("M[3][0]: %.2f\n",c);
	
	system("PAUSE"); 
	return 0;
}
