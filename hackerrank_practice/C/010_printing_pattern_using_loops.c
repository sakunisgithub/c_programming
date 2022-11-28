#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int i, j, k;

    for (i = 1; i <= 2 * n - 1; i++)
    {
        k = n;

        if (i <= n)
        {
            for (j = 1; j <= 2 * n - 1; j++)
            {
                printf("%d ", k);

                if (i > j)
                {
                    k--;
                }

                if (i + j >= 2 * n)
                {
                    k++;
                }
            }
        }
        else
        {
            for (j = 1; j <= 2 * n - 1; j++)
            {
                printf("%d ", k);

                if (i + j < 2 * n)
                {
                    k--;
                }

                if (i <= j)
                {
                    k++;
                }
            }
        }

        printf("\n");
    }

    return 0;
}