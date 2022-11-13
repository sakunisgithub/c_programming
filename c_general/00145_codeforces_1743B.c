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
        printf("1 %d ", size[i]);
        for (int j = 2; j < size[i]; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
        
    }
    
    
    return 0;
}

// https://codeforces.com/problemset/problem/1743/B

/* 
size 7
1 7 2 3 4 5 6 - this is a permutation of size 7
1 - this is one of its subsegmets which is a permutation as well
1 7 2 3 4 5 6 - this is another subsegmet which is a permutation as well
we observe that, in any of the permutations mininum must be 2
because any one of the subsegments must be 1 and one of the subsegments must be the full permutation
so the minimum has to be 2
it can not be 1 because those 2 subsegments must be present
one case of the minimum is when the last number is at the 2nd position and all the rest are in ascending order
size 5
1 5 2 3 4 - permutation
1 - subsegment cum permutation
1 5 2 3 4 - subsegment cum permutation 
size 6 
1 6 2 3 4 5 - permutation
1 - subsegment cum permutation 
1 6 2 3 4 5 - subsegment cum permutation
*/