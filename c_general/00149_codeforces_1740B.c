#include<stdio.h>

int main()
{
    int testcases;
    scanf("%d", &testcases);
    
    unsigned long long int output[testcases];

    for (int i = 0; i < testcases; i++)
    {
        unsigned long long int number_of_cheese_slice;
        scanf("%llu", &number_of_cheese_slice);

        unsigned long long int array_a[number_of_cheese_slice];
        unsigned long long int array_b[number_of_cheese_slice];

        for (int j = 0; j < number_of_cheese_slice; j++)
        {
            scanf("%llu", &array_a[j]);
            scanf("%llu", &array_b[j]);
        }

        unsigned long long int width_array[number_of_cheese_slice];
        unsigned long long int height_array[number_of_cheese_slice];

        // we shall try to maximize the height and minimize the width to get the minimum perimeter
        
        for (int j = 0; j < number_of_cheese_slice; j++)
        {
            if (array_a[j] <= array_b[j])
            {
                width_array[j] = array_a[j];
                height_array[j] = array_b[j];
            }
            else
            {
                width_array[j] = array_b[j];
                height_array[j] = array_a[j];
            }
        }

        // finding the maximum height in the height_array

        unsigned long long int max_height = height_array[0];
        for (int j = 1; j < number_of_cheese_slice; j++)
        {
            if (height_array[j] > max_height)
            {
                max_height = height_array[j];
            }
        }

        unsigned long long int sum = 0;
        for (int j = 0; j < number_of_cheese_slice; j++)
        {
            sum += width_array[j];
        }
        
        output[i] = 2 * (sum + max_height);
        
    }

    for (int i = 0; i < testcases; i++)
    {
        printf("%llu\n", output[i]);
    }
    
    
    return 0;
}

// https://codeforces.com/problemset/problem/1740/B

// https://drive.google.com/file/d/1dVQNhlBqA3pPAMOaFWIs-rD9BkHiktkr/view?usp=sharing : a little discussion of this problem

/* 
I have used unsigned long long int data type with the dimensions of the slices.
I previously used int and unsigned long int, but the submissions failed both the times as in some testcases the dimensions of the slices were too large to fit in the range of int and unsigned long int
*/