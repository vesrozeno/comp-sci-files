//Vitor Emanuel da Silva Rozeno - RA: 211044539
//Projeto01_EscalaCinza.c

#include <stdio.h>
int main()
{   
    //Ponteiros tipo FILE para posição da leitura (in) e escrita (out).
    FILE *in, *out;

    int i,j,n,k,n1,n2,n3,n4;

    //Abertura dos arquivos para leitura ("figura.dat") e escrita ("cinza.dat").
    in = fopen("figura.dat","r");
    out = fopen("cinza.dat","w");

    //Lendo largura (n) e altura (k) contidas na primeira linha do arquivo "figura.dat".
    fscanf(in,"%d",&n);
    fscanf(in,"%d",&k);

    //Escrevendo na primeira linha de "cinza.dat" a largura e altura obtidas em "figura.dat".
    fprintf(out,"%d %d",n,k);
    fprintf(out,"\n");
    
    //Laço de repetição para percorrer as linhas de "figura.dat" e escrever em "cinza.dat".
    for(i=0;i<k;i++)
    {
        for(j=0;j<n;j++)
        {   
            //Obtendo RGB (n1,n2,n3) e calculando a escala de cinza (n4).
            fscanf(in, "%d %d %d",&n1,&n2,&n3);
            n4=(n1+n2+n3)/3;
            //Escrevendo em "cinza.dat" o resultado obtido.
            fprintf(out,"%d ",n4);
        }
        fprintf(out,"\n");
    }
    //Fechamento dos arquivos.
    fclose(in);
    fclose(out);
    return 0;
}