/*
Segundo entregável - Sistemas Operacionais
Grupo:Heitor Xavier de Abreu
      João Lucas Lima
      Vitor Emanuel Rozeno
*/

#include <stdio.h>
#include <stdlib.h>
#include "bcp.h"
#include "mem.h"
#include "proc.h"
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

int main()
{
  int menu = 1;
  char userIn[100];

  // Criando thread para a função ProcessCreate
  pthread_t pcThread; // ProcessCreate
  int PCOut;          // Resultado da pcThread

  // Inicialização da memória
  RAM *mem = malloc(sizeof(RAM));
  mem->blocosDisp = qtBlocos;
  mem->blocosOcu = 0;

  ThreadArgs args;
  // BCP *bcp = NULL;
  BCP bcp = createBCP();

  while (menu)
  {
    printf("\n\nMenu:\n");

    printf(" - [1] ProcessCreate\n");
    printf(" - [2] Ver Dados de Proc e Mem\n");
    printf(" - [3] Ver Detalhes da Execução\n");
    printf(" - (Sair): Digite Sair\n\n");
    printf("----> ");

    scanf(" %[^\n]", userIn);

    char *token = strtok(userIn, " ");
    if (token != NULL)
    {
      if (strcmp(token, "1") == 0)
      {

        args.token = token; // Nome arq
        args.mem = mem;     // Estrutura da memória RAM
        args.bcp = &bcp;    // BCP
        PCOut =
            pthread_create(&pcThread, NULL, processCreate, (void *)&args);

        if (PCOut != 0)
          printf("Erro na criação da thread\n");

        pthread_join(pcThread, NULL); // Aguarda a finalização da thread
      }
      else if (strcmp(token, "2") == 0)
      {
        printBCP(bcp, mem); // Visualiza a bcp de processos e a memória
      }
      else if (strcmp(token, "3") == 0)
      {
        kernel(bcp); // Detalhes de Execução
      }
      else if (strcmp(token, "Sair") == 0)
      {
        menu = 0; // Encerra o programa
      }
      else
      {
        printf("Entrada Inválida. Tente novamente.\n");
      }
    }
    getchar();
  }
  free(mem);
  return 0;
}
