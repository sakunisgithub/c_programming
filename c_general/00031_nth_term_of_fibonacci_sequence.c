#include<stdio.h>

int term(int);
int n;

int main(){
    printf("Enter n=");
    scanf("%d", &n);
    if (n==1)
    {
        printf("The %dst term of the fibonacci sequence is %d", n, term(n));
    }
    else if (n==2)
    {
        printf("The %dnd term of the fibonacci sequence is %d", n, term(n));
    }
    else if (n==3)
    {
        printf("The %drd term of the fibonacci sequence is %d", n, term(n));
    }
    else
    {
    printf("The %dth term of the fibonacci sequence is %d", n, term(n));
    }
    return 0;
}

int term(int n)
{
    if (n==1 || n==2)
    {
        return 1;
    }
    else 
    {
        return term(n-1) + term(n-2);
    }
    
}