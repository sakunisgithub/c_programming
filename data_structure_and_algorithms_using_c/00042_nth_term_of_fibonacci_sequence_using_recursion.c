#include<stdio.h>

int fibonacci(int);

int main()
{
    int n;
    printf("Enter n = ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid input ! Enter a non-negative number !!\n");
    }
    else if (n == 0)
    {
        printf("Fibonacci(0) = 0\n");
    }
    else
    {
        printf("Fibonacci(n) = %d\n", fibonacci(n));
    }
    
    return 0;
}

int fibonacci(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
        
}