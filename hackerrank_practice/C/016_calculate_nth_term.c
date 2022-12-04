#include<stdio.h>

int calculate_nth_term(int, int, int, int);

int main()
{
    int n;
    scanf("%d", &n);

    int a, b, c;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    
    printf("%d", calculate_nth_term(n, a, b, c));
    return 0;
}

int calculate_nth_term(int n, int a, int b, int c)
{
    if (n == 1) 
    {
        return a;
    } 
    else if (n == 2)
    {
        return b;
    }
    else if (n == 3)
    {
        return  c;
    }
    else 
    {
        return calculate_nth_term((n-1), a, b, c) + calculate_nth_term((n-2), a, b, c) + calculate_nth_term((n-3), a, b, c); 
    }
}
