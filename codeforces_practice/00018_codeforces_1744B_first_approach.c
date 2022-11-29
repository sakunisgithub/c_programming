#include<stdio.h>

int main()
{
    int testcases;
    scanf("%d", &testcases);

    for (int i = 0; i < testcases; i++)
    {
        int array_length, number_of_queries;

        scanf("%d", &array_length);
        scanf("%d", &number_of_queries);

        unsigned long long int array[array_length];

        for (int j = 0; j < array_length; j++)
        {
            scanf("%llu", &array[j]);
        }
        
        unsigned long long int query[2];

        for (int j = 0; j < number_of_queries; j++)
        {

            scanf("%llu", &query[0]);
            scanf("%llu", &query[1]);

            unsigned long long int sum = 0;

            if (query[0] == 0)
            {
                for (int i = 0; i < array_length; i++)
                {
                    if (*(array + i) % 2 == 0)
                    {
                        *(array + i) += query[1];
                    }

                    sum += *(array + i);
                }
            }
            else
            {
                for (int i = 0; i < array_length; i++)
                {
                    if (*(array + i) % 2 != 0)
                    {
                        *(array + i) += query[1];
                    }
        
                    sum += *(array + i);
                }
            }
            
            printf("%llu\n", sum);
            
        }
        
        
    }
    
    return 0;
}

// https://codeforces.com/problemset/problem/1744/B