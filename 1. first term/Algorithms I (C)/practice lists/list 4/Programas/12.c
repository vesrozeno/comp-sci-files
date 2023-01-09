#include<stdio.h>
int main()
{
    int homens, mulheres, i;
    float altura, somaAltura, media, porcentagem, maiorM, menorM, maiorF, menorF;
    char sexo;
    homens = 0;
    mulheres = 0;
    somaAltura = 0;
    for (i = 1; i <= 4; i++)
    {
        printf("Digite sua altura: ");
        scanf("%f", &altura);
        getchar();
        printf("Digite seu sexo(M/F): ");
        scanf("%c", &sexo);
        printf("\n");
        switch (sexo)
        {
        case 'm':
        case 'M':
            homens = homens + 1;
            if (homens == 1)
            {
                maiorM = altura;
                menorM = altura;
            }
            if (altura > maiorM)
            {
                maiorM = altura;
            }
            else if (altura < menorM)
            {
                menorM = altura;
            }
            break;
        case 'f':
        case 'F':
            mulheres = mulheres + 1;
            if (mulheres == 1)
            {
                maiorF = altura;
                menorF = altura;
            }
            if (altura > maiorF)
            {
                maiorF = altura;
            }
            else if (altura < menorF)
            {
                menorF = altura;
            }
            somaAltura = somaAltura + altura;
            break;

        default:
            printf("Digite uma entrada válida!");
            i = i - 1;
            break;
        }
    }
    media = somaAltura / mulheres;
    printf("a)\nMaior altura dos homens: %.2f\nMenor altura dos homens: %.2f\n\nMaior altura das mulheres: %.2f\nMenor altura das mulheres: %.2f\n\nb)\nAltura média das mulheres: %.2f\n\nc)\nNúmero de homens:%d\n", maiorM, menorM, maiorF, menorF, media, homens);
    if (homens > mulheres)
    {
        porcentagem = (homens - mulheres) * 100 / mulheres;
        printf("Número de homens %.2f%% maior que o número de mulheres\n", porcentagem);
    }
    else if (homens < mulheres)
    {
        porcentagem = (mulheres - homens) * 100 / homens;
        printf("Número de homens %.2f%% menor que o número de mulheres\n", porcentagem);
    }
    else
    {
        printf("O número de homens e mulheres é igual\n");
    }
    return 0;
}