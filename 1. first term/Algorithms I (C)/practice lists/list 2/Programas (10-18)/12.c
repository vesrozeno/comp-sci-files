#include<stdio.h>
int main()
{
    
    int mesa;
    float refrigerante, cerveja, pizza, almoco, porcao,total, servicos, totalFinal;
    printf("mesa: ");
    scanf("%d",&mesa);
    printf("qt de refrigerante: ");
    scanf("%f",&refrigerante);
    printf("qt de cerveja: ");
    scanf("%f",&cerveja);
    printf("qt de pizza: ");
    scanf("%f",&pizza);
    printf("qt de almoco: ");
    scanf("%f",&almoco);
    printf("qt de porcao: ");
    scanf("%f",&porcao);
    refrigerante = refrigerante * 2.5;
    cerveja = cerveja * 4.0;
    pizza = pizza * 47.30;
    almoco = almoco * 15.0;
    porcao = porcao * 10.5;
    total = refrigerante + cerveja + pizza + almoco + porcao;
    servicos = total * 0.1;
    totalFinal = total + servicos;
    printf("pedido - mesa:%d\ntotal:%.2f reais\nservicos:%.2f reais\ntotal a ser pago:%.2f reais",mesa, total, servicos,totalFinal); 
    return 0;
    }