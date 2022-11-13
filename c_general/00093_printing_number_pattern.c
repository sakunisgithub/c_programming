#include<stdio.h>

// the number pattern is 
// 00000
//  1111
//   222
//    33
//     4
// for n = 5
int main()
{
    int n;
    printf("\nEnter n = ");
    scanf("%d", &n);

    /* int a = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= n-i; k++)
        {
            printf("%d", a);
        }
        printf("\n");
        a++;
    } */

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= i)
            {
                printf("%d", i);
            }
            else
            {
                printf(" ");
            }
            
        }
        printf("\n");
    }
    
    
    return 0;
}