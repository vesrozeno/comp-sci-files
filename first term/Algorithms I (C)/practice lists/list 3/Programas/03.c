#include<stdio.h>
int main()
{
	char sexo;
	printf("Digite seu sexo(M/F): ");
	scanf("%c", &sexo);
	switch(sexo)
	{
		case 'M':case 'm': 
        printf("Você é do sexo masculino.");
        break;
		case 'F':
		case 'f': printf("Você é do sexo feminino.");
        break;
		default: printf("Caractere inválido!");
        break;
    }	
    return 0;
}