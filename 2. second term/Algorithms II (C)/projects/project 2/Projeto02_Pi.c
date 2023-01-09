//Vitor Emanuel da Silva Rozeno - RA: 211044539
//Projeto02_Pi.c

#include <stdio.h>
#include <math.h>

//Protótipos das Funções:
long double term1(int cont_aux, long double aux2, long double aux3, int contador);
long double term2(long double aux1);
long double term3(long double aux1);

//Função principal:
int main()
{
    //Declaração das variáveis necessárias.
    int precisao, cont_aux, contador=0, itera = 0;
    long double pi = 0,aux1 = 1, aux2 = 1, aux3 = 1;

    //Estrutura de repetição com teste no final para manter a variável "precisao" entre 1 e 15.
    do
    {
        printf("Digite a precisão de casas decimais: ");

        //Entrada da variável "precisao".
        scanf("%d",&precisao);
        if(precisao<0||precisao>15)
        {
            printf("\nValor inválido!\n");
        }
    }while(precisao<0||precisao>15);

    //Estrutura de repetição com teste no final para realizar a sequência de somas.
    do
    {
        //O valor de pi/6 será a soma da multipliação dos 3 termos encontrados pelas chamadas de função.
        pi+=term1(cont_aux,aux2,aux3,contador)*term2(aux1)*term3(aux1);
        aux1+=2;
        contador++;
        itera++;
    }while(itera<22);

    //O valr de pi será o valor encontrado na sequência de somas multiplicado por 6.
    pi = 6*pi;

    //Ao final, a saída apresentará o número de casas (precisao) indicado na entrada de dados.
    printf("\nPi: %.*Lf\n\n",precisao, pi);
    return 0;
}
//Corpo das Funções:
//Função para achar o primeiro termo das parcelas da soma.
long double term1(int cont_aux, long double aux2, long double aux3, int contador)
{
    aux2 = 1;
    aux3 = 1;
    //Laço que acompanha o contador da sequência de somas.
    for (cont_aux = 0; cont_aux<=contador; cont_aux++)
    {
        if(cont_aux == 0)
        {
            aux2 = 1;
        }
        //O valor de aux2 será a sequência de multiplicações (1/2*3/4*5/6...).
        else
        {
            aux2 = aux2*(aux3/(aux3+1));
            aux3+=2;
        }
    }
    //A função retorna aux2.
    return aux2; 
}

//Função para achar o segundo termo da parcela de soma.
long double term2(long double aux1)
{
    //O termo sempre será 1/aux com aux1+=2 a cada iteração.
    return 1/aux1;
}

//Função para achar o terceiro termo da parcecla da soma.
long double term3(long double aux1)
{
    //O termo sempre será 1/2 elevado a aux1, com aux1+=2 a cada iteração.
    return pow(0.5,aux1);
    
}
