#include<stdio.h>
// sum of first n natural numbers using recursion
int sum(int);

int n, i, addition = 0;

int main(){

    printf("Enter n=");
    scanf("%d", &n);
    printf("The sum of first %d natural numbers is %d", n, sum(n));
    
    return 0;
}

int sum(int n)
{
    if (n==0)
    {
        return 0;
    }
    else if (n==1)
    {
        return 1;
    }
    
    
    i = n + sum(n-1);
    return i;   
}