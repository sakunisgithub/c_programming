#include<stdio.h>

int main()
{
    int y, w;
    scanf("%d", &y);
    scanf("%d", &w);

    int g;
    (y >= w) ? (g = y) : (g = w);

    if (g == 1)
    {
        printf("1/1");
    }
    else if (g == 2)
    {
        printf("5/6");
    }
    else if (g == 3)
    {
        printf("2/3");
    }
    else if (g == 4)
    {
        printf("1/2");
    }
    else if (g == 5)
    {
        printf("1/3");
    }
    else if (g == 6)
    {
        printf("1/6");
    }
    
    return 0;
}

// https://codeforces.com/problemset/problem/9/A