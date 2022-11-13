#include<stdio.h>
/* for n = 4 this program will print
1 
2 3 
4 5 6 
7 8 9 10 
 */

int main()
{
    int n;
    printf("\nEnter n = ");
    scanf("%d", &n);

    int number = 1;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", number+count);
            count++;
        }
        printf("\n");
    }
    
    return 0;
}