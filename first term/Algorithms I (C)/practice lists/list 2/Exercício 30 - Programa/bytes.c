#include<stdio.h>
int main()
{
    char carac;
    int inteiro;
    float real;
    double realD;
    unsigned char uChar;
    unsigned int uInt;
    long int lInt;
    unsigned long int ulInt;
    long double lDouble;
    printf("char:%lu bytes\nint:%lu bytes\nfloat:%lu bytes\ndouble:%lu bytes\n",sizeof(carac), sizeof(inteiro), sizeof(real), sizeof(realD));
    printf("unsigned char:%lu bytes\nunsigned int:%lu bytes\nlong int:%lu bytes\nunsigned long int:%lu bytes\nlong double:%lu bytes\n",sizeof(uChar), sizeof(uInt), sizeof(lInt), sizeof(ulInt), sizeof(lDouble));

    return 0;
}