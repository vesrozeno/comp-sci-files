#include <stdio.h>
int main(){
    float A, B, aInicial;
    printf("A: ");
    scanf("%f", &A);
    printf("B: ");
    scanf("%f", &B);
    aInicial = A;
    A = B;
    B = aInicial;
    printf("Troca:\nA:%.2F\nB:%.2f",A,B);
    return 0;
    
}