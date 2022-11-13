#include<stdio.h>

// the pattern is
// * * * * * * * * *
//   * * * * * * *
//     * * * * *
//       * * *
//         *
// for n = 5
int main()
{
    int n;
    printf("\nEnter n = ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < 2*n; j++)
        {
            if ( (j >= i) && (j<= 2*n - i ) )
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