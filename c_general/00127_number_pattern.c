#include<stdio.h>
/* for n = 5, this pattern will print
5
4 5
3 4 5
2 3 4 5
1 2 3 4 5
 */

int main()
{
    int n;
    printf("\nEnter n = ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int number = n - i + 1;
        for (int j = number; j <= n; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    
    return 0;
}