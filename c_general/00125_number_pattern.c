#include<stdio.h>

/* for n = 5 this program will print
1
1 1       
1 0 1     
1 0 0 1   
1 0 0 0 1 
 */

int main()
{
    int n;
    printf("\nEnter n = ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == i || j == 1)
            {
                printf("1 ");
            }
            else
            {
                printf("0 ");
            }
            
        }
        printf("\n");
    }
    
    return 0;
}