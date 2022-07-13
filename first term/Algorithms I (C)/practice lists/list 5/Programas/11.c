#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 500
int main()
{
    int vetor[MAX], temp, inicio, fim;
    char input;
    srand(time(NULL));
    for(int i = 0; i<MAX; i++)
    {
        vetor[i] = rand()%MAX;
    }
    do
    {
        printf("\n==========BEM VINDO!==========\n\n Menu: \n(A) Ordenar elementos em ordem crescente\n(B) Ordenar elementos em ordem decrescente\n(C) Imprimir todo o vetor\n(D) Imprimir as posições de um certo intervalo\n\n DIGITE <S> ou <s> PARA SAIR\n");
        printf("\nSelecione uma operação ====> ");
        scanf("%c", &input);
        getchar();
        if(input == 'S')
        {
            input = 's';
        }
        switch(input)
        {
            case 'A':
            case 'a':
            {
                for (int i=0;i<MAX; i++)
                {
                    for(int j=i+1;j<MAX;j++)
                    {
                        if (vetor[i]>vetor[j])
                        {
                            temp=vetor[i];
                            vetor[i]=vetor[j];
                            vetor[j]=temp;
                        }
                    }
                }
                printf("\n");
                printf("Vetor em ordem crescente: \n");
                for(int i=0;i<MAX;i++)
                    printf(" %d",vetor[i]);
                printf("\n");
                printf("\n\nPressione Enter para continuar . . .\n");
            }
            break;
            case 'B':
            case 'b':
            {
                for (int i=0;i<MAX; i++)
                {
                    for(int j=i+1;j<MAX;j++)
                    {
                        if (vetor[i]<vetor[j])
                        {
                            temp=vetor[i];
                            vetor[i]=vetor[j];
                            vetor[j]=temp;
                        }
                    }
                }
                printf("\n");
                printf("Vetor em ordem decrescente: \n");
                for(int i=0;i<MAX;i++)
                    printf(" %d",vetor[i]);
                printf("\n");
                printf("\n\nPressione Enter para continuar . . .\n");
            }
            break;
            case'c':
            case'C':
            {
                for(int i = 0; i<MAX; i++)
                {
                    printf(" %d", vetor[i]);
                }
                printf("\n");
                printf("\n\nPressione Enter para continuar . . .\n");
            }
            break;
            case'd':
            case'D':
            {   do
                {
                    printf("\n\nQual a posição inicial?: \n");
                    scanf("%d", &inicio);
                    if(inicio<0)
                        printf("\n\nPosição inexistente. Tente novamente . . .\n");
                }while(inicio<0);
                do
                {
                    printf("\n\nQual a posição final?: \n");
                    scanf("%d", &fim);
                    if(fim<0)
                        printf("\n\nPosição inexistente. Tente novamente . . .\n");
                }while(fim<0);
                printf("\n\n");
                for(int i = inicio; i<=fim; i++)
                {
                    printf(" %d", vetor[i]);
                }
                printf("\n");
                getchar();
                printf("\n\nPressione Enter para continuar . . .\n");
            }
            break;
            case 's':
            case 'S':
            {
                printf("\n\nSaindo . . .");
                printf("\n\nPressione Enter para continuar . . .\n");
            }
            break;
            default:
            {
                printf("\n\nEntrada inválida. Tente novamente . . .\n");
                printf("\n\nPressione Enter para continuar . . .\n");
            }
            break;
        }
        getchar();
    }while(input != 's');
    return 0;
}
