//Mini Prova 07 - Vitor Rozeno - Unesp 2021 - 06.08.2021
#include <stdio.h>

int main()
{
    double anterior,erromax,proximo,errocor;
    printf("\n\n Solução ===> x^2 - 3x + 2 = 0 \n\n");
    printf("\n\n Digite o valor aproximado para a RAIZ: \n\n");
    scanf("%lf", &anterior);
    printf("\n\n Digite o ERRO MÁXIMO aceitável: \n\n");
    scanf("%lf", &erromax);
    anterior =  (anterior !=1.5)?(anterior):(anterior*anterior);
    if(erromax >= 0){
        do{
        proximo = anterior - ((anterior*anterior - 3*anterior+2) /(2*anterior - 3));
        
        printf("\nA aproximação corrente para a Raiz é: %.10f\n",proximo);
        errocor=  (proximo-anterior >= 0)?(proximo-anterior):(anterior - proximo);
        anterior = proximo;   
    }while(errocor >= erromax);
    printf("\nSolução: %.10f\n",proximo);
        
        
    }else{printf("\nERRO.");}
    

    return 0;
}