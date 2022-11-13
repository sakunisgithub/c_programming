#include<stdio.h>

// the pattern is
// 5       5       5       5       5
// 4       4       4       4        
// 3       3       3
// 2       2
// 1
// for n = 5

int main()
{
    int n;
    printf("\nEnter n = ");
    scanf("%d", &n);

    int m = n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            printf("%d\t", m);
        }
        m--;
        printf("\n");
    }
    
    return 0;
}