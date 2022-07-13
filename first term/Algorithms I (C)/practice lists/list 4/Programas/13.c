#include<stdio.h>
int main()
{
    float ana, felis, crescAna, crescFelis;
    int anos;
    ana = 1.5;
    crescAna = 0.02;
    felis = 1.1;
    crescFelis = 0.03;

    anos = 0;
    while(ana > felis)
    {
        ana = ana + crescAna;
        felis = felis + crescFelis;
        anos ++;
    }while(ana > felis);
    printf("%d anos\n", anos);
    return 0;
}