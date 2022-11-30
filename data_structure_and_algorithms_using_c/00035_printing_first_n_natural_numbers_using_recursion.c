#include<stdio.h>

void print_number(int, int);

int main()
{
    int n;
    printf("Enter n = ");
    scanf("%d", &n);

    print_number(1, n);
    return 0;
}

void print_number(int start, int stop)
{
    if (start == stop + 1)
    {
        return;
    }
    else
    {
        printf("%d\n", start);
        start++;
        print_number(start, stop);
    }
    
}