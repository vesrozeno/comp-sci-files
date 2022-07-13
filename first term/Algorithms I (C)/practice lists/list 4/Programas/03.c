#include<stdio.h>
int main()
{
	int codigo;
    for(int i = 1; i<=10; i++)
    {
         printf("\nDigite o codigo do produto: ");
        scanf("%d", &codigo);
        printf("\n");
        switch(codigo)
        {
            case 1:
                printf("Procedência: Sul.\n");
                break;
            case 2:
                printf("Procedência: Norte.\n");
                break;
            case 3:
                printf("Procedência: Leste.\n");
                break;
            case 4:
                printf("Procedência: Oeste.\n");
                break;
            case 5:case 6:
                printf("Procedência: Nordeste.\n");
                break;
            case 7:case 8:case 9:
                printf("Procedência: Sudeste.\n");
                break;
            case 10:case 11:
                printf("Procedência: Centro-Oeste.\n");
                break;
            case 12:case 13:case 14:case 15:
                printf("Procedência: Nordeste.\n");
                break;
            default:
                printf("Procedência: Importado.\n");
                break;
        }   
    }
	
    return 0;
}