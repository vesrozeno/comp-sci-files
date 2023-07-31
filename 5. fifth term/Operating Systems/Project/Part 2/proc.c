/*
Segundo entregável - Sistemas Operacionais
Grupo:Heitor Xavier de Abreu
      João Lucas Lima
      Vitor Emanuel Rozeno
*/

#include "proc.h"
#include "bcp.h"
#include "mem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>

Processo *readProcess(const char *filename)
{
  Processo *programa = malloc(sizeof(Processo));
  programa->nome = (char *)malloc(100 * sizeof(char));
  programa->lista = (char *)malloc(20 * sizeof(char));
  int i;
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }

  // Lê o cabeçalho do programa sintético
  fscanf(file, "%s\n", programa->nome);
  fscanf(file, "%d\n", &programa->idSeg);
  fscanf(file, "%d\n", &programa->prioridade);
  fscanf(file, "%d\n", &programa->tSeg);
  fscanf(file, " %[^\n]", programa->lista);
  /*
  for (i = 0; i < sizeof(programa->lista); i++)
  {
    if (programa->lista[i] == ' ')
    {
      programa->lista[i] = programa->lista[i + 1];
      programa->lista[i + 1] = ' ';
    }
  }*/
  // Lê os comandos do programa sintético
  programa->numCommands = 0;
  while (fscanf(file, "%s", programa->commands[programa->numCommands]) != EOF)
  {
    programa->numCommands++;
  }

  fclose(file);
  return programa;
}

void printProcess(Processo *programa)
{
  int i;
  printf("Nome do programa: %s\n", programa->nome);
  printf("Identificador do segmento: %d\n", programa->idSeg);
  printf("Prioridade original: %d\n", programa->prioridade);
  printf("Tamanho do segmento: %d\n", programa->tSeg);
  printf("Semáforos: %s\n", programa->lista);
  printf("Tempo restante: %d\n", programa->time);
  printf("Número de comandos: %d\n", programa->numCommands);
  printf("Comandos:\n");
  for (i = 0; i < programa->numCommands; i++)
  {
    printf("%s\n", programa->commands[i]);
  }
}

int calculateRemainingTime(Processo *programa, int currentTime)
{
  int remainingTime = 0;
  int aux;

  for (int i = 0; i < programa->numCommands; i++)
  {
    char command[15];
    strcpy(command, programa->commands[i]);
    // char command = programa->commands[i][0];

    if (strcmp(command, "exec") == 0)
    {
      aux = atoi(programa->commands[i + 1]);
      remainingTime += aux;
    }
    else if (strcmp(command, "print") == 0)
    {
      aux = atoi(programa->commands[i + 1]);
      remainingTime += aux;
    }
    else if (strcmp(command, "write") == 0)
    {
      aux = atoi(programa->commands[i + 1]);
      remainingTime += aux;
    }
    else if (strcmp(command, "read") == 0)
    {
      aux = atoi(programa->commands[i + 1]);
      remainingTime += aux;
    }
  }

  // Subtrai o tempo já decorrido
  remainingTime -= currentTime;

  return remainingTime;
}

void *processCreate(void *arg)
{
  ThreadArgs *args = (ThreadArgs *)arg;
  char *arqPrograma = args->token;
  RAM *memo = args->mem;
  BCP *bcp = args->bcp;
  Processo *novoProcesso = malloc(sizeof(Processo));

  // Solicitar o nome do arquivo do programa sintético ao usuário
  char filename[100];
  printf("Digite o nome do programa sintético (com a extensão do arquivo): ");
  scanf("%s", filename);

  novoProcesso = readProcess(filename);

  // Calcular o tempo restante do processo
  novoProcesso->time = calculateRemainingTime(novoProcesso, 0);
  novoProcesso->stopped = 0;
  // Verifica o tamanho
  novoProcesso->tBlocos = ceil(novoProcesso->tSeg / 8);

  if (memAloc(memo, novoProcesso->tBlocos) == 1)
  {
    printf("Memória suficiente.\n");
  }
  else
  {
    printf("Memória insuficiente.\n");
  }
  // Inserir o novo processo na bcp encadeada
  insertProcess(bcp, novoProcesso);

  printProcess(novoProcesso);

  printf("Processo criado e adicionado ao BCP.\n");
  pthread_exit(NULL);
}
