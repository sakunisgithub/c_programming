#include<stdio.h>

int main(){
    
    float a ;

    printf("Enter The Celsius Temperature\n");

    scanf("%f", &a);

    float b = (9.0*a)/5.0 + 32.0;

    printf("The Fahrenheit Temperature is %.2f", b); // .2 is for 2 decimal places

    return 0;
}