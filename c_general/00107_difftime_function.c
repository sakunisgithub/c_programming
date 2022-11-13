#include<stdio.h>
#include<time.h>

int main()
{
    time_t start, end;
    start = time(NULL);
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
    
    end = time(NULL);
    printf("\nThe program took %f seconds to run.", difftime(end, start));

    return 0;
}