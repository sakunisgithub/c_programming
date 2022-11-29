#include<stdio.h>
#include<stdlib.h>

int main()
{
    int weight;
    scanf("%d", &weight);

    if (weight % 2 == 0 && weight > 2)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    
    return 0;
}

// https://codeforces.com/problemset/problem/4/A