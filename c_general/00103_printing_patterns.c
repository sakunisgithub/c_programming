#include<stdio.h>

// the pattern is
// 1
// 0       0
// 3       3       3
// 0       0       0       0
// 5       5       5       5       5
// for n = 5

int main()
{
    int n;
    printf("\nEnter n = ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i % 2 == 0)
            {
                printf("0\t");
            }
            else
            {
                printf("%d\t", i);
            }
            
        }
        printf("\n");
    }
    // printf("Press any key to exit.\n");
    // _getch();
    // exit(0);
    return 0;
}