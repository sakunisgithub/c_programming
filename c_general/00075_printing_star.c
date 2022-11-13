#include<stdio.h>

// the pattern is 
//     *
//    **
//   ***
//  ****
// *****
// for n = 5

// see https://www.youtube.com/watch?v=SHkMR09y9v0&list=PLu0W_9lII9ahSEQv6cHtu8JBXNgK2_QMX&index=11 for a different approach
int main()
{
    int n;
    printf("\nEnter n = ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }

        for (int k = 1; k <= i; k++)
        {
            printf("*");
        }
        
        printf("\n");
    }
    
    return 0;
}