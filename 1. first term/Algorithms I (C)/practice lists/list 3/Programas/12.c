#include<stdio.h>
int main()
{

	int num1, num2, num3, num4, num5;
	printf("Digite cinco números inteiros:\n");
	scanf("%d", &num1);
	scanf("%d", &num2);
	scanf("%d", &num3);
	scanf("%d", &num4);
	scanf("%d", &num5);
    if(num1>=num2 && num1>=num3 && num1>=num4 && num1>=num5)
    {
    	printf("\nMaior número: %d\n",num1);
    }
    else if (num2>=num1 && num2>=num3 && num2>=num4 && num2>=num5)
    {
    	printf("\nMaior número: %d\n",num2);
    }
    else if (num3>=num1 && num3>=num2 && num3>=num4 && num1>=num5)
    {
    	printf("\nMaior número: %d\n",num3);
    }
    else if (num4>=num1 && num4>=num2 && num4>=num3 && num4>=num5)
    {
    	printf("\nMaior número: %d\n",num4);
    }
    else if (num5>=num1 && num5>=num2 && num5>=num3 && num5>=num4)
    {
    	printf("\nMaior número: %d\n",num5);
    }
    if(num1<=num2 && num1<=num3 && num1<=num4 && num1<=num5)
    {
    	printf("\nMenor número:%d\n", num1);
    }
    else if (num2<=num1 && num2<=num3 && num2<=num4 && num2<=num5)
    {
    	printf("\nMenor número:%d\n", num2);
    }
    else if (num3<=num1 && num3<=num2 && num3<=num4 && num3<=num5)
    {
    	printf("\nMenor número:%d\n", num3);
    }
    else if (num4<=num1 && num4<=num2 && num4<=num3 && num4<=num5)
    {
    	printf("\nMenor número:%d\n", num4);
    }
    else if (num5<=num1 && num5<=num2 && num5<=num3 && num5<=num4)
    {
    	printf("\nMenor número:%d\n", num5);
    }
    return 0;
}