#include<stdio.h>

int max_of_four(int, int, int, int);

int main()
{
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    int max = max_of_four(a, b, c, d);

    printf("%d", max);

    return 0;
}

int max_of_four(int a, int b, int c, int d)
{
    int w1, w2;
    (a >= b) ? (w1 = a) : (w1 = b);
    (c >= d) ? (w2 = c) : (w2 = d);

    if (w1 >= w2)
    {
        return w1;
    }
    else
    {
        return w2;
    }
    
}