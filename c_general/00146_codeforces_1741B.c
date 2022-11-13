#include<stdio.h>

int main()
{
    int testcases;
    scanf("%d", &testcases);

    int size[testcases];

    for (int i = 0; i < testcases; i++)
    {
        scanf("%d", &size[i]);
    }
    
    for (int i = 0; i < testcases; i++)
    {
        int number = size[i];

        if ( (number % 2 != 0) && (number != 3) )
        {
            for (int j = 0; j < size[i]/2; j++)
            {
                printf("%d ", number);
                number--;
            }

            for (int j = 1; j <= number; j++)
            {
                printf("%d ", j);
            }
            
            printf("\n");
        }
        else if (number % 2 == 0)
        {
            for (int j = number; j >= 1; j--)
            {
                printf("%d ", j);
            }
            printf("\n");
            
        }
        else
        {
            printf("-1");
            printf("\n");
        }
    }
    
    return 0;
}

// https://codeforces.com/problemset/problem/1741/B

/* 
1 2 3 4 5 6 7
7 6 5 4 3 2 1 the middle most digit does not satisfy the condition if n is odd
7 6 5 1 2 3 4 this solves the above problem

1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1 so no problem if n is even
*/