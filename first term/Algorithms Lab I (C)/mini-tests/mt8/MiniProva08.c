#include <stdio.h>
#include <stdlib.h>
int main()
{
    float matrizA[2][3], matrizB[3][4], resultante[2][4], mediaAritmetica, auxiliar = 0, soma = 0;

    //Entrada de Dados - Inicialização das Matrizes
    printf("Digite valores para a matriz A:\n");
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<3; j++)
        {
            scanf("%f", &matrizA[i][j]);
        }
    }
    printf("Digite valores para a matriz B:\n");
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<4; j++)
        {
            scanf("%f", &matrizB[i][j]);
        }
    }

    system("clear");

    //Saída de Dados - Matrizes Digitadas
    printf("\n\nMatriz A:\n");
    for(int i = 0; i<2; i++)
    {
        printf("\n");
        for(int j = 0; j<3; j++)
        {
            printf("%.2f\t", matrizA[i][j]);
        }
    }
    printf("\n\nMatriz B:\n");
    for(int i = 0; i<3; i++)
    {
        printf("\n");
        for(int j = 0; j<4; j++)
        {
            printf("%.2f\t", matrizB[i][j]);
        }
    }

    //Multiplicação das Matrizes
    for(int i = 0; i < 2; i++) 
    {
		for( int j = 0; j < 4; j++) 
        {
			
			resultante[i][j] = 0;
			for( int x = 0; x < 3; x++) 
            {
				auxiliar +=  matrizA[i][x] * matrizB[x][j];
			}

			resultante[i][j] = auxiliar;
			auxiliar = 0;
		}
	}

    //Saída de Dados - Matriz Resultante
    printf("\n\nMatriz Resultante:\n");
    for(int i = 0; i<2; i++)
    {
        printf("\n");
        for(int j = 0; j<4; j++)
        {
            printf("%.2f\t", resultante[i][j]);
        }
    }

    //Cálculo da soma e quantidade dos elementos positivos 
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<4; j++)
        {
            if(resultante[i][j]>=0)
            {
                soma+=resultante[i][j];
                auxiliar ++;
            }
        }
    }

    //Saída de Dados Final - Média Aritmética ou Não há valores positivos 
    if(auxiliar>0)
    {
        mediaAritmetica = soma/auxiliar;
        printf("\n\nMédia Aritmética dos nros positivos: %.2f\n", mediaAritmetica);
    }
    else
    {
        printf("\n\nNão há números positivos para calcularmos a média deles.\n");
    }


    return 0;
}