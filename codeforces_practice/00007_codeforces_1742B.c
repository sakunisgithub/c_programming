#include<stdio.h>

int main()
{
    int testcases;
    scanf("%d", &testcases);

    int array_lengths[testcases];

    int output[testcases];

    for (int i = 0; i < testcases; i++)
    {
        output[i] = 1;

        scanf("%d", &array_lengths[i]);

        int numbers[array_lengths[i]];

        for (int j = 0; j < array_lengths[i]; j++)
        {
            scanf("%d", &numbers[j]);
        }
        
        for (int j = 0; j < array_lengths[i]; j++)
        {
            for (int k = j+1; k < array_lengths[i]; k++)
            {
                if (numbers[j] == numbers[k])
                {
                    output[i] = 0;
                    break;
                }
            }
            if (output[i] == 0) 
            {
                break;
            }
            
        }

    }

    for (int i = 0; i < testcases; i++)
    {
        if (output[i] == 1)
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

// https://codeforces.com/problemset/problem/1742/B

/* 
the given numbers can be sorted in strictly increasing order if no two of the numbers are same
we are assuming that the given array can be sorted in strictly increasing order. so we make output[i] = 1
and if two of the numbers match, we change the output[i] to 0 and use two break statements to break out of the two for loops
*/