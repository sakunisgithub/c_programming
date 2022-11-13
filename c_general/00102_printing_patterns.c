#include<stdio.h>

// the pattern is
// 1       3       5       7       9
// 3       5       7       9
// 5       7       9
// 7       9
// 9
// for n = 5

int main()
{
    int n;
    printf("\nEnter n = ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j >= i)
            {
                printf("%d\t", (2*j-1));
                
            }
            
        }
        printf("\n");
    }
    
    return 0;
}