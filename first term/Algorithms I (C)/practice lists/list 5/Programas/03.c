#include<stdio.h>
int main()
{
    int A[5], B[5], C[5];
    printf("Digite valores para os vetores: ");
    for(int i = 1; i <= 10; i++)
    {
        if(i<=5)
        {
        printf("\n%d: ", i);
        scanf("%d", &A[i-1]);
        }
        else
        {
            printf("\n%d: ", i);
            scanf("%d", &B[i-6]);
        }
    }
    printf("\n========VETORES=========\n");
    for(int i = 0; i < 10; i++)
    {
        if(i<=4)
        {
            printf("\nA[%d]: %d",i, A[i]);
        }
        else
        {
            printf("\nB[%d]: %d",i - 5, B[i-5]);
        }
    }
    for(int i = 0; i < 5; i++)
    {
        C[i] = A[i];
    }
    for(int i = 0; i < 5; i++)
    {
        A[i] = B[4-i];
    }

    for(int i = 0; i < 5; i++)
    {
        B[i] = C[4-i];
    }
    printf("\n==============TROCA============\n");
    for(int i = 0; i < 10; i++)
    {
        if(i<=4)
        {
            printf("\nA[%d]: %d",i, A[i]);
        }
        else
        {
            printf("\nB[%d]: %d",i-5, B[i-5]);
        }
    }


    return 0;
}