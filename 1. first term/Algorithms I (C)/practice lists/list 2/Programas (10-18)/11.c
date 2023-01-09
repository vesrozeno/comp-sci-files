#include <stdio.h>
int main(){
    float real, dolar, euro, dolreal, eureal;
    printf("cotacao euro: ");
    scanf("%f", &euro);
    printf("cotacao dolar: ");
    scanf("%f", &dolar);
    printf("quantidade em real a ser convertida: ");
    scanf("%f", &real);
    dolreal = real/dolar;
    eureal = real/euro;
    printf("cotacao euro:€%.2f\ncotacao dolar:U$%.2f\nqt (real) a ser convertida:R$%.2f\n",euro, dolar, real);
    printf("conversao: euro - €%.2f\nconversao: dolar - U$%.2f",eureal, dolreal);
    return 0;
    
}