#include <stdio.h>
int main()
{
    int codigo;
    char controle;
    do
    {
        printf("Digite o codigo do produto: ");
        scanf("%d", &codigo);
        switch (codigo)
        {
        case 1:
            printf("Alimento não perecível.\n");
            break;
        case 2:
        case 3:
        case 4:
            printf("Alimento perecível.\n");
            break;
        case 5:
        case 6:
            printf("Vestuário.\n");
            break;
        case 7:
            printf("Higiene pessoal.\n");
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            printf("Limpeza e utensílios domésticos.\n");
            break;
        default:
            printf("Código Inválido.\n");
            break;
        }
        printf("Prosseguir com a execução?(S/N)");
        getchar();
        scanf("%c", &controle);
    } while (controle == 's' || controle == 'S');
    return 0;
}