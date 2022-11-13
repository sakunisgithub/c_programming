#include<stdio.h>

int main(){
    
    int a;

    printf("Enter Your Dividend\n");

    scanf("%d", &a);
    
    int b;

    printf("Enter Your Divisor\n");

    scanf("%d", &b);

    float c = a%b;

    if(c==0){
            printf("The number is Divisible\n");
    }
    else{
            printf("The number is Not Divisible\n");
    }

    printf("The remainder is %f", c);

    return 0;
}