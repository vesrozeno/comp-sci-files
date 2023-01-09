#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_ARQUIVO "turma.txt"
#define NOME_ARQUIVO_INDICE "index.txt"
#define TAM 128 // TAMANHO DO REGISTRO
// DEFININDO STRUCTS:
// STRUCT REGISTRO
struct registro
{
    char nome[60];
    char curso[50];
    char ra[18];
};
// STRUCT INDICE
struct indice
{
    char ra[18];
    int index;
};
int main()
{
    int menu;
    int contador = 1;

    struct registro reg;
    struct indice ind;

    // ARQUIVOS "TURMA" E "INDEX"
    FILE *arq;
    FILE *arqInd;

    do
    {
        // MENU
        printf("1-Gravar Aluno\n2-Buscar Aluno\n3-Fechar Progama\n----> ");
        scanf("%d", &menu);
        switch (menu)
        {
        // GRAVAR ALUNO:
        case 1:

            arq = fopen(NOME_ARQUIVO, "a+");
            // JÁ OBTENDO O INDICE DESSE ALUNO, QUE SERÁ O FINAL DO ARQUIVO
            fseek(arq, 0, SEEK_END);
            ind.index = ftell(arq);

            printf("Lendo dados\n");

            getchar();

            printf("\nEntre com o nome do aluno: ");
            scanf("%[^\n]", reg.nome);
            getchar();

            printf("\nEntre com a curso: ");
            scanf("%[^\n]", reg.curso);
            getchar();

            printf("\nEntre com a RA: ");
            scanf("%[^\n]", reg.ra);
            getchar();

            printf("\n");

            fprintf(arq, "%s", reg.nome);
            fprintf(arq, "%s", "|"); // DELIMITADOR: "|"
            fprintf(arq, "%s", reg.curso);
            fprintf(arq, "%s", "|");
            fprintf(arq, "%s", reg.ra);
            fprintf(arq, "%s", "|");

            arqInd = fopen(NOME_ARQUIVO_INDICE, "a+");

            // CALCULANDO CARACTERES USADOS PARA PODER PREENCHER O RESTO DO REGISTRO COM "."
            int tamanho_nome = strlen(reg.nome);
            int tamanho_curso = strlen(reg.curso);
            int tamanho_ra = strnlen(reg.ra, 18);
            int tamanho_campos = tamanho_nome + tamanho_curso + tamanho_ra + 3;

            for (int i = 1; i < (128 - tamanho_campos); i++)
            {
                fprintf(arq, "%s", ".");
            }
            fprintf(arq, "%s", "\n");

            // ESCREVENDO O RA E INDICE EM INDEX.TXT
            strcpy(ind.ra, reg.ra);

            fprintf(arqInd, "%s|%d\n", ind.ra, ind.index);

            // FECHANDO OS ARQUIVOS PARA SALVAR
            fclose(arq);
            fclose(arqInd);
            break;
        case 2:

            arqInd = fopen(NOME_ARQUIVO_INDICE, "r");

            char *campos, linha[TAM + 1], ra[18], raInd[18], *camposReg, linhaReg[TAM + 1];
            int indice, achou, resultadoCmp, indiceFinal;
            printf("\nDigite o RA do aluno: ");
            scanf("%s", ra);
            //LENDO O ARQUIVO INDEX EM BUSCA DO RA DIGITADO
            while (!feof(arqInd))
            {
                if (fgets(linha, 128, arqInd))
                {
                    campos = strtok(linha, "|");

                    strcpy(raInd, campos);
                    campos = strtok(NULL, "|");
                    indice = atoi(campos);
                    campos = strtok(NULL, "|");

                    resultadoCmp = strcmp(raInd, ra);
                    if (resultadoCmp == 0)
                    {
                        achou = 1;
                        indiceFinal = indice;
                    }
                }
            }
            //CASO ACHE, O INDICE ENCONTRADO JUNTO SERÁ USADO PARA OBTER AS INFO. DO ALUNO
            if (achou == 1)
            {

                arq = fopen(NOME_ARQUIVO, "r");
                fseek(arq, indiceFinal, SEEK_SET);
                if (fgets(linhaReg, TAM + 1, arq))
                {
                    camposReg = strtok(linhaReg, "|");
                    printf("\nNome do Aluno: %s\n", camposReg);
                    camposReg = strtok(NULL, "|");
                    printf("Curso do Aluno: %s\n", camposReg);
                    camposReg = strtok(NULL, "|");
                    printf("RA do Aluno: %s\n\n", camposReg);
                    camposReg = strtok(NULL, "|");
                }
                fclose(arq);
            }
            else
            {
                printf("\nAluno não encontrado!\n\n");
            }

            fclose(arqInd);
            break;
        case 3:
            printf("Fechando Programa...");
            break;
        default:
        }
    } while (menu != 3);

    return 0;
}