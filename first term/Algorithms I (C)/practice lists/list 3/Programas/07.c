#include<stdio.h>
int main()
{
	int codigo;
	printf("Digite o codigo do produto: ");
	scanf("%d", &codigo);
	switch(codigo)
    {
        case 1:
        	printf("Procedência: Sul.");
            break;
        case 2:
        	printf("Procedência: Norte.");
            break;
        case 3:
        	printf("Procedência: Leste.");
            break;
        case 4:
        	printf("Procedência: Oeste.");
            break;
        case 5:case 6:
        	printf("Procedência: Nordeste.");
            break;
        case 7:case 8:case 9:
        	printf("Procedência: Sudeste.");
            break;
        case 10:case 11:
        	printf("Procedência: Centro-Oeste.");
            break;
        case 12:case 13:case 14:case 15:
        	printf("Procedência: Nordeste.");
            break;
        default:
        	printf("Procedência: Importado.");
            break;
    }
    return 0;
}