#include<stdio.h>

// the pattern is
// 1
// 2       1
// 1       2       3
// 4       3       2       1
// 1       2       3       4       5
// for n = 5

int main()
{
    int n;
    printf("\nEnter n = ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            for (int k = 1; k <= i; k++)
            {
                printf("%d\t", k);
            }
                
        }

        else
        {
            for (int k = i; k >= 1; k--)
            {
                printf("%d\t", k);
                    
            }
                
        }
        printf("\n");
    }
    
    return 0;
}