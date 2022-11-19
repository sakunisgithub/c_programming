#include<stdio.h>

int main()
{
    int testcases;
    scanf("%d", &testcases); // number of testcases

    int n = testcases * 3;
    int numbers[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]); // taking the numbers as input
    }

    int a, b, c;

    for (int i = 0; i < testcases; i++)
    {
        a = numbers[i*3];
        b = numbers[i*3 + 1];
        c = numbers[i*3 + 2];

        if (a == b + c)
        {
            printf("YES\n");
        }
        else if (b == c + a)
        {
            printf("YES\n");
        }
        else if (c == a + b)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        
    }
    
    
    return 0;
}

// https://codeforces.com/problemset/problem/1742/A