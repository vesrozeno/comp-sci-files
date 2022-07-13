#include<stdio.h>
#include<stdlib.h>
int main()
{
    int addOrSub, input, prods, total, change;
    int estoque[5] = {12,19,10,6,3};
    float preco[5] = {24.50, 12.99, 30.00, 15.75, 10.50}, addSubPreco;
    do{
        system("clear");
        printf("\n\n=========Bem vindo!==========\n\n");
        printf("\n======== Selecione uma operação ========\n\n(1) Aumentar estoque\n(2) Baixar estoque\n(3) Visualizar estoque de um produto\n(4) Visualizar estoque total\n(5) Aumentar preço\n(6) Diminuir preço\n(7) Trocar produto\n(8) Sair\n\nOperação selecionada ==> ");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
            {
                do{
                    printf("\n\nAumentar estoque de qual produto?\n\n(1) Produto 1\n(2) Produto 2\n(3) Produto 3\n(4) Produto 4\n(5) Produto 5\n\nProduto selecionado ====> ");
                    scanf("%d", &prods);
                    printf("\nAdicionar quantas unidades ao estoque?: ");
                    scanf("%d", &addOrSub);
                    switch(prods)
                    {
                        case 1:
                        {
                            estoque[0] = estoque[0] + addOrSub;
                        }
                        break;
                        case 2:
                        {
                            estoque[1] = estoque[1] + addOrSub;
                        }
                        break;
                        case 3:
                        {
                            estoque[2] = estoque[2] + addOrSub;
                        }
                        break;
                        case 4:
                        {
                            estoque[3] = estoque[3] + addOrSub;
                        }
                        break;
                        case 5:
                        {
                            estoque[4] = estoque[4] + addOrSub;
                        }
                        default:
                            printf("\n\nEntrada inválida. Tente novamente . . .\n\nPressione Enter para continuar . . .\n\n");
                            getchar();
                        break;
                    }
                    getchar();
                }while(prods>5||prods<=0);
                printf("\n\nEstoque atualizado! %d unidades adicionadas ao estoque de Produto %d\n\nPressione Enter para continuar . . .\n\n", addOrSub, prods);
            }
            break;
            case 2:
            {
                do{
                    printf("\nBaixar estoque de qual produto?\n\n(1) Produto 1\n(2) Produto 2\n(3) Produto 3\n(4) Produto 4\n(5) Produto 5\n\nProduto selecionado ====> ");
                    scanf("%d", &prods);
                    printf("\nSubtrair quantas unidades do estoque?: ");
                    scanf("%d", &addOrSub);
                    switch(prods)
                    {
                        case 1:
                        {
                            estoque[0] = estoque[0] - addOrSub;
                        }
                        break;
                        case 2:
                        {
                            estoque[1] = estoque[1] - addOrSub;
                        }
                        break;
                        case 3:
                        {
                            estoque[2] = estoque[2] - addOrSub;
                        }
                        break;
                        case 4:
                        {
                            estoque[3] = estoque[3] - addOrSub;
                        }
                        break;
                        case 5:
                        {
                            estoque[4] = estoque[4] - addOrSub;
                        }
                        default:
                            printf("\n\nEntrada inválida. Tente novamente . . .\n\nPressione Enter para continuar . . .\n\n");
                            getchar();
                        break;
                        }
                    getchar();
                }while(prods>5||prods<=0);
                printf("\n\nEstoque atualizado! %d unidades subtraídas do estoque de Produto %d\n\nPressione Enter para continuar . . .\n\n", addOrSub, prods);
            }
            break;
            case 3:
            {
                do{
                printf("\n\nVisualizar estoque de qual produto?\n\n(1) Produto 1\n(2) Produto 2\n(3) Produto 3\n(4) Produto 4\n(5) Produto 5\n\nProduto selecionado ====> ");
                scanf("%d", &prods);
                switch(prods)
                {
                    case 1:
                    {
                        printf("\n\nEstoque de Produto %d: %d unidades.\n\n", prods, estoque[0]);
                    }
                    break;
                    case 2:
                    {
                        printf("\n\nEstoque de Produto %d: %d unidades.\n\n", prods, estoque[1]);
                    }
                    break;
                    case 3:
                    {
                        printf("\n\nEstoque de Produto %d: %d unidades.\n\n", prods, estoque[2]);
                    }
                    break;
                    case 4:
                    {
                        printf("\n\nEstoque de Produto %d: %d unidades.\n\n", prods, estoque[3]);
                    }
                    break;
                    case 5:
                    {
                        printf("\n\nEstoque de Produto %d: %d unidades.\n\n", prods, estoque[4]);
                    }
                    default:
                        printf("\n\nEntrada inválida. Tente novamente . . .\n\nPressione Enter para continuar . . .\n\n");
                        getchar();
                    break;
                    }
                    getchar();
                }while(prods>5||prods<=0);
            }
            break;
            case 4:
            {
                total = estoque[0]+estoque[1]+estoque[2]+estoque[3]+estoque[4];
                printf("\n\nEstoque total = %d\n\n", total);
                getchar();
            }
            break;
            case 5:
            {
                do
                {
                    printf("\n\nAumentar preço de qual produto?\n\n(1) Produto 1\n(2) Produto 2\n(3) Produto 3\n(4) Produto 4\n(5) Produto 5\n\nProduto selecionado ====> ");
                    scanf("%d", &prods);
                    printf("\nQuanto será adicionado ao preço do produto?: ");
                    scanf("%f", &addSubPreco);
                    switch(prods)
                    {
                        case 1:
                        {
                            preco[0] = preco[0] + addSubPreco;
                        }
                        break;
                        case 2:
                        {
                            preco[1] = preco[1] + addSubPreco;
                        }
                        break;
                        case 3:
                        {
                            preco[2] = preco[2] + addSubPreco;
                        }
                        break;
                        case 4:
                        {
                            preco[3] = preco[3] + addSubPreco;
                        }
                        break;
                        case 5:
                        {
                            preco[4] = preco[4] + addSubPreco;
                        }
                        default:
                            printf("\n\nEntrada inválida. Tente novamente . . .\n\nPressione Enter para continuar . . .\n\n");
                            getchar();
                        break;
                    }
                    getchar();
                }while(prods>5||prods<=0);
                printf("\n\nPreço atualizado! %.2f reais adicionadas ao preço do Produto %d\n\nPressione Enter para continuar . . .\n\n", addSubPreco, prods);
            
            }
            break;
            case 6:
            {

                do{
                    printf("\n\nDiminuir preço de qual produto?\n\n(1) Produto 1\n(2) Produto 2\n(3) Produto 3\n(4) Produto 4\n(5) Produto 5\n\nProduto selecionado ====> ");
                    scanf("%d", &prods);
                    printf("\nQuanto será subtraído do preço do produto?: ");
                    scanf("%f", &addSubPreco);
                    switch(prods)
                    {
                        case 1:
                        {
                            preco[0] = preco[0] - addSubPreco;
                        }
                        break;
                        case 2:
                        {
                            preco[1] = preco[1] - addSubPreco;
                        }
                        break;
                        case 3:
                        {
                            preco[2] = preco[2] - addSubPreco;
                        }
                        break;
                        case 4:
                        {
                            preco[3] = preco[3] - addSubPreco;
                        }
                        break;
                        case 5:
                        {
                            preco[4] = preco[4] - addSubPreco;
                        }
                        default:
                            printf("\n\nEntrada inválida. Tente novamente . . .\n\nPressione Enter para continuar . . .\n\n");
                            getchar();
                        break;
                    }
                    getchar();
                }while(prods>5||prods<=0);
                printf("\n\nPreço atualizado! %.2f reais subtraídos do preço do Produto %d\n\nPressione Enter para continuar . . .\n\n", addSubPreco, prods);
            }
            break;
            case 7:
            {
                do{
                    printf("\n\nQual produto você está trocando?\n\n(1) Produto 1\n(2) Produto 2\n(3) Produto 3\n(4) Produto 4\n(5) Produto 5\n\nProduto selecionado ====> ");
                    scanf("%d", &prods);
                    switch(prods)
                    {
                        case 1:
                        {
                            estoque[0] = estoque[0] - 1;
                        }
                        break;
                        case 2:
                        {
                            estoque[1] = estoque[1] - 1;
                        }
                        break;
                        case 3:
                        {
                            estoque[2] = estoque[2] - 1;
                        }
                        break;
                        case 4:
                        {
                            estoque[3] = estoque[3] - 1;
                        }
                        break;
                        case 5:
                        {
                            estoque[4] = estoque[4] - 1;
                        }
                        default:
                            printf("\n\nEntrada inválida. Tente novamente . . .\n\nPressione Enter para continuar . . .\n\n");
                            getchar();
                        break;
                    }
                    getchar();
                }while(prods>5||prods<=0);
                do{
                    printf("\nGostaria de trocar por qual produto?:\n\n(1) Produto 1\n(2) Produto 2\n(3) Produto 3\n(4) Produto 4\n(5) Produto 5\n\nProduto selecionado ====>  ");
                    scanf("%d", &change);
                    switch(change)
                    {
                        case 1:
                        {
                            estoque[0] = estoque[0] + 1;
                        }
                        break;
                        case 2:
                        {
                            estoque[1] = estoque[1] + 1;
                        }
                        break;
                        case 3:
                        {
                            estoque[2] = estoque[2] + 1;
                        }
                        break;
                        case 4:
                        {
                            estoque[3] = estoque[3] + 1;
                        }
                        break;
                        case 5:
                        {
                            estoque[4] = estoque[4] + 1;
                        }
                        default:
                            printf("\n\nEntrada inválida. Tente novamente . . .\n\nPressione Enter para continuar . . .\n\n");
                            getchar();
                        break;
                    }
                    getchar();
                }while(prods>5||prods<=0);
                printf("\n\nTroca realizada! Produto %d trocado por um Produto %d\n\nPressione Enter para continuar . . .\n\n", prods, change);
            
            }
            break;
            case 8:
                printf("\n\nSaindo . . .\n\n");
            break;
            default:
            {
                system("clear");
                printf("\n\nEntrada inválida. Tente novamente . . .\n\nPressione Enter para continuar\n\n");
                getchar();
            }
            break;
        }
        getchar();
   }while(input != 8);
    return 0;
}