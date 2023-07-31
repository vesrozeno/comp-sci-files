/*
Segundo entregável - Sistemas Operacionais
Grupo:Heitor Xavier de Abreu
      João Lucas Lima
      Vitor Emanuel Rozeno
*/

#ifndef __PROC
#define __PROC
#define MAX_COMMAND_LENGTH 100

#include "bcp.h"
#include "mem.h"
#include <stdio.h>

// Estrutura para representar um processo
typedef struct processo
{
  char *nome;    // Nome
  int tBlocos;   // Tamanho do segmento (BLOCOS)
  int tRest;     // Tempo restante (u.t.)
  char *lista;   // Lista de semáforos
  FILE *arqProg; // Arquivo do programa
  int pos;       // Posição no arquivo
  int idSeg;     // Identificador do segmento
  int prioridade;
  int tSeg; // Tamanho do segmento (KB)
  int numCommands;
  int stopped;
  char commands[MAX_COMMAND_LENGTH][50];
  int time;
  struct processo *prox;

} Processo;

// Estrutura para os argumentos da thread
typedef struct threadargs
{
  char *token; // Token da thread
  RAM *mem;    // Ponteiro para a memória
  BCP *bcp;    // Ponteiro para a lista de BCPs
} ThreadArgs;

Processo *readProcess(const char *filename);
void printProcess(Processo *program);
int calculateRemainingTime(Processo *program, int currentTime);
void *processCreate(void *arg);

#endif
