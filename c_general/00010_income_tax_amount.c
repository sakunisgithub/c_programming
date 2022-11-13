#include<stdio.h>

int main(){
    
    float income, a, b, c;
    
    printf("Enter your income amount in lakhs\n");
    scanf("%f", &income);

    

    if (income<=2.5)
    {
        printf("You do not have to pay any tax.");
    }
    if (income>2.5 && income<=5.0)
    {
        a = ((income-2.5)*5)/100;
        printf("You have to pay %f lahhs as taxes.", a);
    }
    if (income>5.0 && income<=10.0)
    {
        b = ((income-5.0)*20)/100 + ((5.0-2.5)*5)/100;
        printf("You have to pay %f lahhs as taxes.", b);
    }
    if (income>10.0)
    {
        c = ((income-10.0)*30)/100 + ((10-5.0)*20)/100 + ((5.0-2.5)*5)/100;
        printf("You have to pay %f lahhs as taxes.", c);
    }
    
    
    return 0;
}