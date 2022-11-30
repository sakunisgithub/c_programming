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

void print_number(int num)
{
    if (num <= 0)
    {
        return;
    }
    else
    {
        printf("%d\n", num);
        num--;
        print_number(num);
    }
    
}