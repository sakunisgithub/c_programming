#include<stdio.h>

float farenheit(float);

float a;

int main(){
    printf("Enter the temperature in celcius\n");
    scanf("%f", &a);
    printf("The temperature in farenheit is %f", farenheit(a));
    return 0;
}

float farenheit(float a)
{
    return (9*a)/5.0 + 32 ;
}