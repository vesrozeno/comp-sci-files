//Vitor Rozeno - MP10 - LATP 1 - Unesp 2021
#include <stdio.h>
#include <cstdlib>

int main()
{

    printf("\n\nReta média - mínimos quadrados\n\n");
    printf("\n\nNúmeros de pontos:\n\n");
//variáveis
    int n;
    scanf("%d",&n);
    double x, y;
    double sx=0, sx2=0, sx3=0, sx4=0, sy=0, sxy=0, sx2y=0;
//otimizando... para que não seja usada a memória
    for(int i=0 ; i<n ; i++)
    {
        printf("\n\nValor de x: \n\n");
        scanf("%lf", &x);
        printf("\n\nValor de y: \n\n");
        scanf("%lf", &y);
        sx+=x;
        sx2+=x*x;
        sy+=y;
        sxy+=x*y;
    }
    double a=(n * sxy - sx * sy)/(n * sx2 - sx * sx);
    double b=(sx2 * sy - sxy * sx)/(n * sx2 - sx * sx);
    printf("\n\nReta média: y = %.3lf * x + %.3f \n\n", a, b);
    printf("\n\n");
    return(0);
}
