/*
Segundo entregável - Sistemas Operacionais
Grupo:Heitor Xavier de Abreu
      João Lucas Lima
      Vitor Emanuel Rozeno
*/

#include "bcp.h"
#include "proc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

BCP createBCP()
{
  BCP bcp;
  bcp.first = NULL;
  bcp.last = NULL;
  return bcp;
}

void insertProcess(BCP *bcp, Processo *processo)
{
  Processo *novoProcesso = (Processo *)malloc(sizeof(Processo));
  if (novoProcesso == NULL)
  {
    printf("Erro\n");
    return;
  }
  novoProcesso = processo;
  novoProcesso->prox = NULL;

  if (bcp->first == NULL)
  {
    // A lista está vazia, insere como primeiro elemento
    bcp->first = novoProcesso;
    bcp->last = novoProcesso;
  }
  else
  {
    // Encontra a posição correta para inserção
    Processo *current = bcp->first;
    Processo *previous = NULL;

    while (current != NULL && current->time <= novoProcesso->time)
    {
      previous = current;
      current = current->prox;
    }

    if (previous == NULL)
    {
      // Insere no início da lista
      novoProcesso->prox = bcp->first;
      bcp->first = novoProcesso;
    }
    else if (current == NULL)
    {
      // Insere no final da lista
      previous->prox = novoProcesso;
      bcp->last = novoProcesso;
    }
    else
    {
      // Insere no meio da lista
      previous->prox = novoProcesso;
      novoProcesso->prox = current;
    }
  }
}

void printBCP(BCP bcp, RAM *mem)
{
  Processo *current = bcp.first;

  while (current != NULL)
  {
    printf("Name: %s, Time: %d\n", current->nome, current->time);
    current = current->prox;
  }
  printf("Memória Usada: %d kB\n", mem->blocosOcu * 8);
  printf("Memória Livre: %d kB\n", mem->blocosDisp * 8);
}
void kernel(BCP bcp)
{
  Processo *proc = bcp.first;
  // proc = bcp.first;
  int i, time = 0;
  char command[15];

  while (proc != NULL)
  {
    i = 0;
    while (1)
    {

      // i = proc->stopped;
      strcpy(command, proc->commands[i]);
      if (strcmp("exec", command) == 0)
      {
        proc->time -= atoi(proc->commands[i + 1]);
        printf("Executing %s | Remaining Time: %d\n", proc->nome, proc->time);
      }
      else if (strcmp(command, "print") == 0)
      {
        proc->time -= atoi(proc->commands[i + 1]);
        printf("Printing %s | Remaining Time: %d\n", proc->nome, proc->time);
      }
      else if (strcmp(command, "write") == 0)
      {
        proc->time -= atoi(proc->commands[i + 1]);
        printf("Writing %s | Remaining Time: %d\n", proc->nome, proc->time);
      }
      else if (strcmp(command, "read") == 0)
      {
        proc->time -= atoi(proc->commands[i + 1]);
        printf("Reading %s | Remaining Time: %d\n", proc->nome, proc->time);
      }
      i++;
      if (proc->time <= 0)
        break;
      // if(proc == NULL)
      //     break;
    }
    proc = proc->prox;
  }
}
