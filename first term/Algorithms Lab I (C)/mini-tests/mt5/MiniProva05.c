#include <stdio.h>
int main()
{
    //DECLARAÇÃO DAS VARIÁVEIS
    char senha[31];
    int i = 0;
    int maiuscula = 0;
    //ENTRADA DE DADOS
    printf("\n\t\tCRIE UMA SENHA:\n\n\t\tREQUISITOS:\n\n(1)Limite de 30 caracteres\n(2)Todos maiúsculos\n(3) Em Sequência\n====> ");
    scanf("%s", senha);
    //ESTRTURA DE REPETIÇÃO CONTENDO UMA ESTRUTURA DE DECISÃO PARA VERIFICAR SE A SENHA CORRESPONDE AOS REQUISITOS
    while (senha[i] != '\0')
    {
        if ((senha[i] >= 65) && (senha[i] <= 90) && (senha[i] == (senha[i - 1] + 1)) || i == 0)
        {
            maiuscula++;
        }
        i++;
    }
    //SAÍDA DE DADOS DEPENDENTE DA ESTRUTURA DE DECISÃO, VERIFICANDO SE A SENHA É VÁLIDA
    if (i == maiuscula)
    {
        printf("\n\nSenha criada!\n\n ");
    }
    else
    {
        printf("\n\nSenha Inválida! Cumpra os requisitos\n\n ");
    }
}

