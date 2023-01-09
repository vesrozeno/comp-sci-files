//================================================================
// Nome Do Arquivo: ShellSort.c
//
// Descrição: Implementação do algoritmo de ordenação Shell
//================================================================
 
// Libs
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

 // Defines
//multiplica o tamanho do vetor por 3 a cada iteração
#define MULTIPLICADOR 2
//número de iterações
#define N_ITERACOES 20

//numero de elementos do vetor
long int MAX = 100;

 //Protótipo de Funções ===========================================
// Protótipo da função de ordenação
void shell_sort(unsigned int *a, int size);
// Protótipo da função geradora de números aleatórios
void random_generator(unsigned int *a, int size);
 
// Função main
// Main Function
int main(int argc, char** argv)
{
 int i;
 double start, end, time_taken;
 unsigned int *vet;

 for (int j = 0; j < N_ITERACOES; j++)
 {
    vet = calloc(MAX, sizeof(int));
     //Gerar números aleatórios para o vetor
     random_generator(vet, MAX);

     // inicia o cronometro
     start = 0;
     end = 0;
     time_taken = 0;
     start = clock();
     // Ordena os valores
     // Order values
     shell_sort(vet, MAX);

     // encerra o cronometro
     end = clock();

     time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC) *(1000);

     printf(" \n%ld %lf", MAX, time_taken);
     MAX *= MULTIPLICADOR;
     free(vet);
 }

 return 0;
}
 
// Função de ordenação Shell
// Shellsort function
void shell_sort(unsigned int *a, int size)
{
 int i , j , value;
 int count = 1;
 long int S[1000];
 int i2 = 0;
 int i3 = 0;
 long int n2, n3;
 int lastIn = 0;

 S[0] = 1;

 do
 {
    //gera 2^p*3^q numbers (3-smooth numbers)
     n2 = 2 * S[i2];
     n3 = 3 * S[i3];
     if (n2 > n3)
     {
         lastIn++;
         S[lastIn] = n3;
     }
     else
     {
         lastIn++;
         S[lastIn] = n2;
     }
     if (n2 <= n3)
         i2++;
     if (n2 >= n3)
         i3++;
     count++;

 } while (S[lastIn] < size);
 do{
  lastIn--;
  for(i = S[lastIn]; i < size; i++) {
   value = a[i];
   j = i - S[lastIn];
    
   while (j >= 0 && value < a[j]) {
    a[j + S[lastIn]] = a[j];
    j -= S[lastIn];
   }
   a[j + S[lastIn]] = value;
  }
 }while(S[lastIn] > 1);
}

void random_generator(unsigned int *a, int size){
 int i = 0;

 for (i = 0; i < size; i++){
    a[i] = rand() % 65000;
 }

}