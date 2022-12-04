#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int matrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum_1 = 0, sum_2 = 0;

    for (int i = 0; i < n; i++)
    {
        sum_1 += matrix[i][i];
    }

    for (int i = 0; i < n; i++)
    {
        sum_2 += matrix[i][n-i-1];
    }

    int diff = sum_1 - sum_2;
    printf("%d", abs(diff));

    return 0;
}
