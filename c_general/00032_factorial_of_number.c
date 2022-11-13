#include<stdio.h>
// factorial of a number using functions
int factorial(int);
int n;
int main(){
    printf("Enter n=");
    scanf("%d", &n);
    printf("%d!=%d",n, factorial(n));
    return 0;
}

int factorial(int n)
{
    if (n==0 || n==1)
    {
        return 1;
    }
    
    return n*factorial(n-1);
}