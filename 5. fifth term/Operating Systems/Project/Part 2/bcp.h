/*
Segundo entregável - Sistemas Operacionais
Grupo:Heitor Xavier de Abreu
      João Lucas Lima
      Vitor Emanuel Rozeno
*/

#ifndef __BCP
#define __BCP

typedef struct processo Processo;
typedef struct ram RAM;

typedef struct bcp
{
  Processo *first;
  Processo *last;
} BCP;

BCP createBCP();
void insertProcess(BCP *bcp, Processo *process);
void printBCP(BCP bcp, RAM *mem);
void kernel(BCP bcp);

#endif