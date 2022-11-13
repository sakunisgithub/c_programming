#include<stdio.h>
#include<time.h>

// clock_t clock();
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
    printf("\nTime elapsed is %u seconds.", clock()/CLOCKS_PER_SEC);
    return 0;
}