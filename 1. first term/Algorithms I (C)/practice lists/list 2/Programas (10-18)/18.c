#include<stdio.h>
int main()
{

	float qtKm, qtComb, media;
    printf("Quilometros rodados: ");
	scanf("%f",&qtKm);
    printf("COmbustivel utilizado: ");
	scanf("%f",&qtComb);
	media = qtKm/qtComb;
	printf("Relaçao Quilometros/Litros:%.2f Km/L",media);
    return 0;
}