#include<stdio.h>

// the pattern is
// * * * * * 
// * * * *   
// * * *
// * *
// *
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
            if (i+j <= n+1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
            
        }
        printf("\n");
    }
    
    return 0;
}