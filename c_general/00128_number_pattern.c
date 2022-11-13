#include<stdio.h>
/* for n = 9, this program will print
9 
9 7
9 7 5
9 7 5 3
9 7 5 3 1
 */

int main()
{
    int n;
    printf("\nEnter n = ");
    scanf("%d", &n);

    for (int i = 1; i <= n/2 + 1; i++)
    {
        int number = n;
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", number);
            number -= 2;
        }
        printf("\n");
    }
    
    return 0;
}