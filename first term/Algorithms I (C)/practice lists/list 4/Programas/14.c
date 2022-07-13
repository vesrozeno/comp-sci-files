#include <stdio.h>
int main()
{
    int voto, voto1=0, voto2=0, voto3=0, voto4=0, votoNulo=0, votoBranco=0, percentual;
    printf("Legenda:\n(1) Candidato 1\n(2) Candidato 2\n(3) Candidato 3\n(4) Candidato 4\n(5) Voto Nulo\n(6) Voto Branco\n(0) Finalizar Votação");
    do
    {
        printf("\nInsira seu voto: ");
        scanf("%d", &voto);
        switch(voto)
        {
            case 0:
                printf("\n\nEncerrando votação . . .");
            break;
            case 1:
                printf("Você votou no Candidato 01!");
                voto1++;
            break;
            case 2:
                printf("Você votou no Candidato 02!");
                voto2++;
            break;
            case 3:
                printf("Você votou no Candidato 03!");
                voto3++;
            break;
            case 4:
                printf("Você votou no Candidato 04!");
                voto4++;
            break;
            case 5:
                printf("Você votou Nulo.");
                votoNulo++;
            break;
            case 6:
                printf("Você votou em Branco.");
                votoBranco++;
            break;
            default:
                printf("Voto inválido, tente novamente.");
            break;
        }
    }while(voto!=0);
    percentual = ((votoNulo+votoBranco)*100)/(voto1+voto2+voto3+voto4+votoNulo+votoBranco);
    printf("\n\nTotal de Votos:\nCandidato 01: %d votos\nCandidato 02: %d votos\nCandidato 03: %d votos\nCandidato 04: %d votos\nVotos Nulos: %d votos\nVotos Brancos: %d votos\n", voto1, voto2, voto3, voto4, votoNulo, votoBranco);
    printf("\nPercentual dos votos nulos e brancos sobre o total: %d%%\n", percentual);
    return 0;
}