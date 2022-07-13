#include<stdio.h>
int main()
{
    int num1, num2, num3;
	printf("Digite três números inteiros diferentes:\n");
	scanf("%d", &num1);
	scanf("%d", &num2);
	scanf("%d", &num3);
    if(num1>num2 && num1>num3)
    {
    	printf("\nMaior número: %d\n",num1);
    }
    else if (num2>num1 && num2>num3)
    {
    	printf("\nMaior número: %d\n",num2);
    }
    else if (num3>num1 && num3>num2)
    {
    	printf("\nMaior número: %d\n",num3);
    }
    else
    {
    	printf("\nDigite números diferentes!\n");
    }
    return 0;
}