#include<stdio.h>

int power(int, int);

int main()
{
    int n, a;
    printf("\nEnter your base number = ");
    scanf("%d", &n);
    printf("\nEnter the exponent = ");
    scanf("%d", &a);

    int result = power(n, a);

    printf("\nThe result is %d", result);
    
    return 0;
}

int power(int x, int y)
{
    int product = 1;

    for (int i = 0; i < y; i++)
    {
        product = product * x;
    }

    return product;
}