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

        unsigned long long int sum = 0;

        int odd = 0, even = 0;

        for (int j = 0; j < array_length; j++)
        {
            scanf("%llu", &array[j]);
            sum += array[j]; // sum of the array elements
            (array[j] % 2 == 0) ? (even++) : (odd++); // calculating the number of even and odd elements in the initial array
        }
        
        unsigned long long int query[2];

        for (int j = 0; j < number_of_queries; j++)
        {

            scanf("%llu", &query[0]);
            scanf("%llu", &query[1]);

            if (query[0] == 0)
            {
                sum = sum + (even * query[1]); // as query[1] is added to all the even numbers
                if (query[1] % 2 != 0) // updating the number of even and odd numbers
                {
                    odd += even;
                    even = 0;
                }
            }
            else
            {
                sum = sum + (odd * query[1]); // as all query[1] is added to all the odd numbers
                if (query[1] % 2 != 0) // updating the number of even and odd numbers
                {
                    even += odd;
                    odd = 0;
                }
                
            }
            
            printf("%llu\n", sum);
            
        }
        
        
    }
    
    return 0;
}

// https://codeforces.com/problemset/problem/1744/B

// https://drive.google.com/file/d/1urkgBOzynE9SOKlycOgcCP3Ci879T-O6/view?usp=sharing