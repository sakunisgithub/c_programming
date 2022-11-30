#include<stdio.h>

void print_number(int, int);

int main()
{
    int n;
    printf("Enter n = ");
    scanf("%d", &n);

    print_number(n, 1);
    return 0;
}

void print_number(int num1, int num2)
{
    if (num1 < num2)
    {
        return;
    }
    else
    {
        print_number(num1, num2 + 1);
        printf("%d\n", num2);
    }
    
}