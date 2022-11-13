#include<stdio.h>

int main(){
    
    float a;
    
    printf("Enter The Principle Amount\n");
    scanf("%f", &a);

    float b;
    printf("Enter The Number of Years\n");
    scanf("%f", &b);

    float c;
    printf("Enter The Interest Rate in Percentage\n");
    scanf("%f", &c);

    float d = (a*b*c)/100;
    printf("The Amount of Simple Interest is %f\n", d);

    printf("The Final Amount is %f", a+d);

    return 0;
}