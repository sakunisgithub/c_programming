#include<stdio.h>
// the pattern is 
//     *     
//    ***
//   *****
//  *******
// *********
// for n = 5

int main()
{
    int n;

    printf("\nEnter n = ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 2*n - 1; j++)
        {
            if (j >= (n-1-i) && j<= (n-1+i))
            {
                printf("*");
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