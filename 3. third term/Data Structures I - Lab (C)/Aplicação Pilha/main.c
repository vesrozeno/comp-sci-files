#include <stdio.h>
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;
#define boolean int;
#define MAX 101

char pilha[100];
int topo;
//----------------------------------

//Funções para manusear a pilha
//----------------------------------
void Define()
{
	topo = -1;
}
void Push(char x)
{
	topo++;
	pilha[topo] = x;
}
char Pop()
{
	char c = pilha[topo];
	topo --;
	return c;
}
boolean Vazia()
{
	return (topo == -1);
}
//----------------------------------

/* Retorna TRUE, se a string contém uma sequência
válida (parênteses + colchetes), FALSE caso contrário*/
boolean SequenciaValida(char s[])
{
	int i;
	char c;

	Define();
	
	for(i = 0; s[i] != '\0'; i++)
	{	
		switch(s[i])
		{
			case ')': 
			
				if (Vazia()) return FALSE;
				c = Pop();//Desempilha o correspondente a esq.
				if(c!='(')return FALSE;	
				break;
			case ']':
			
				if(Vazia())return FALSE;
				c = Pop(); //Desempilha o correspondente a esq.
				if(c != '[')return FALSE;	
				break;
			default: Push(s[i]);					
		}//fim seitch;
	}//fim for;
	return Vazia();
}//fim função;


int main() {
	
	char sequencia[MAX];
	printf("Digite uma sequencia de parenteses e colchetes");
	scanf("%s", sequencia);
	
	if(SequenciaValida(sequencia))
	{
		printf("Sequencia valida");
	}
	else
	{
		printf("Sequencia invalida");
	}
	return 0;
}
