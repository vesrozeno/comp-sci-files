#include<stdio.h>
int main()
{
    int valorDiaria, diaria, taxa, totalPagar, hospede, totalHotel, totalDiarias;
    char  nome[20], endereco[100], fone[15], cidade[50], estado[10];
    totalHotel = 0;
    totalDiarias = 0;
    valorDiaria = 300;
    for(hospede = 1; hospede<=3; hospede++)
    {
        printf("Digite seu nome: ");
        fgets(nome, 20, stdin);
        printf("Digite seu telefone: ");
        fgets(fone, 15, stdin);
        printf("Digite seu endereço: ");
        fgets(endereco, 100, stdin);
        printf("Digite sua cidade: ");
        fgets(cidade, 50, stdin);
        printf("Digite seu estado: ");
        fgets(estado, 10, stdin);
        printf("Digite o número de diárias: ");
        scanf("%d", &diaria);
        getchar();
        if(diaria<15)
        {
            taxa = 20;
        }
        else if(diaria=15)
        {
            taxa = 14;
        }
        else
        {
            taxa = 12;
        }
        totalPagar = (diaria*valorDiaria)+taxa;
        printf("Hóspede %d:\n====Dados Pessoais====\n\nNome:%s\nEndereço:%s\nCidade:%s\nEstado:%s\nFone:%s\n====Dados de Hospedagem====\n\nNúmero de diárias: %d diárias\nTaxa de serviços: R$%d\nTotal a pagar:R$%d\n===============\n", hospede, nome, endereco, cidade, estado, fone, diaria, taxa, totalPagar);
        totalHotel = totalHotel + totalPagar;
        totalDiarias = totalDiarias + diaria;
    }
    printf("===============LEVANTAMENTO FINAL DO HOTEL==========\n\nTotal ganho pelo hotel: R$%d\nTotal de diárias: R$%d\n\n===========================================", totalHotel, totalDiarias);
    return 0;
}