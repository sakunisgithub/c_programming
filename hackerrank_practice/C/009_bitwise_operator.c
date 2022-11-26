#include<stdio.h>

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    // for any given n, there will be n(n-1)/2 number of combinations
    int alpha = (n*(n-1)) / 2;

    int result_of_and[alpha], result_of_or[alpha], result_of_xor[alpha];

    int count = 0;

    for (int i = 1; i <= n-1; i++)
    {
        int a = i;
        for (int j = 1; j <= n-i; j++)
        {
            int b = a+j;

            result_of_and[count] = a & b;
            result_of_or[count] = a | b;
            result_of_xor[count] = a ^ b;
            count++;
        }
    }

    int max_and;

    for (int i = 0; i < alpha; i++)
    {
        if (*(result_of_and + i) < k)
        {
            max_and = *(result_of_and + i);
            break;
        }
    }
    
    for (int i = 0; i < alpha; i++)
    {
        if (*(result_of_and + i) < k && *(result_of_and + i) > max_and)
        {
            max_and = *(result_of_and + i);
        }
    }
       
    int max_or;

    for (int i = 0; i < alpha; i++)
    {
        if (*(result_of_or + i) < k)
        {
            max_or = *(result_of_or + i);
        }
    }

    for (int i = 0; i < alpha; i++)
    {
        if (*(result_of_or + i) < k && *(result_of_or + i) > max_or)
        {
            max_or = *(result_of_or + i);
        }
    }

    int max_xor;

    for (int i = 0; i < alpha; i++)
    {
        if (*(result_of_xor + i) < k)
        {
            max_xor = *(result_of_xor + i);
        }
    }

    for (int i = 0; i < alpha; i++)
    {
        if (*(result_of_xor + i) < k && *(result_of_xor + i) > max_xor)
        {
            max_xor = *(result_of_xor + i);
        }
    }
    

    printf("%d\n", max_and);
    printf("%d\n", max_or);
    printf("%d\n", max_xor);

    return 0;

} 