//Vitor Rozeno - MP11 - LATP 1 - Unesp 2021
#include <stdio.h>
#include <cstdlib>
int main()
{
    printf("\nReta média - mínimos quadrados\n");
    printf("\nNúmeros de pontos:\n");
    //variáveis
    int n;
    scanf("%d",&n);
    double x, y, sx=0, sx2=0, sx3=0, sx4=0, sy=0, sxy=0, sx2y=0;
    //atribuição das variáveis acima
    for(int i=0 ; i<n ; i++)
    {
        printf("\nValor de x: \n");
        scanf("%lf", &x);
        printf("\nValor de y: \n");
        scanf("%lf", &y);
        sx += x;
        sx2 += x*x;
        sx3 += x*x*x;
        sx4 += x*x*x*x;
        sy += y;
        sxy += x*y;
        sx2y += x*x*y;
    }
    //determinantes - pelo método de Sarrus
    double det = sx2*sx2*sx2 + sx3*sx3*n + sx4*sx*sx - n*sx2*sx4 -sx*sx2*sx3 - sx*sx2*sx3;
    double detA = sy*sx2*sx2 + sx*sx*sx2y + n*sxy*sx3 - n*sx2*sx2y - sx3*sx*sy - sxy*sx*sx2;
    double detB = sx2*sxy*sx2 + sy*sx*sx4 + n*sx2y*sx3 - n*sxy*sx4 - sy*sx3*sx2 - sx*sx2y*sx2;
    double detC = sx2*sx2*sx2y + sx*sxy*sx4 + sy*sx3*sx3 - sy*sx2*sx4 - sx*sx3*sx2y - sx2*sxy*sx3;
    //atribuindo os valores de a, b e c
    double a = detA/det;
    double b = detB/det;
    double c = detC/det;
    //apresentando a equação da parabóla
    printf("\nParábola: y = %.3lf * x^2 + %.3f * x + %.3f \n", a, b, c);
    printf("\n");
    return 0;
}
