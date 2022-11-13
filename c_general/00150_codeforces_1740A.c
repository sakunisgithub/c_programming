#include<stdio.h>

int main()
{
    int testcases;
    scanf("%d", &testcases);

    int output[testcases];

    for (int i = 0; i < testcases; i++)
    {
        int prime_n;
        scanf("%d", &prime_n);

        if (prime_n == 2)
        {
            output[i] = 7;
        }
        else
        {
            output[i] = 3;
        }
        
    }

    for (int i = 0; i < testcases; i++)
    {
        printf("%d\n", output[i]);
    }
    
    
    return 0;
}

// https://codeforces.com/problemset/problem/1740/A

/* 
there is only one even prime number which is 2
so if the given prime number is 2 we say the other prime number is 7
if the given prime number is not 2, then it must be odd
an odd prime number + 3(another odd prime number) = an even number (so never prime except 2)
*/