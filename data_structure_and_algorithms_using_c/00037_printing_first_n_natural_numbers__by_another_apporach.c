#include<stdio.h>

void print_number(int);

int main()
{
    int n;
    printf("Enter n = ");
    scanf("%d", &n);

    print_number(n);
    return 0;
}

void print_number(int number)
{
    if (number <= 0)
    {
        return;
    }
    else
    {
        print_number(number-1);
        printf("%d\n", number);
    }
    
}