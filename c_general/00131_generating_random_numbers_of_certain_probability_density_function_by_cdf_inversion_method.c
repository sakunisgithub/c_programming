#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define F_inverse(x) log( (1+x) / (1-x) )

int main()
{
    float numbers[500];

    srand(time(NULL));
    for (int i = 0; i < 500; i++)
    {
        numbers[i] = ( rand() /(float)RAND_MAX); // to generate numbers in (0,1)

    }

    float final_numbers[500], sum = 0;

    for (int i = 0; i < 500; i++)
    {
        final_numbers[i] = F_inverse(numbers[i]);
        sum += final_numbers[i];
    }
    
    printf("\nThe generated sample that follows the given probability density function is :: \n");
    for (int i = 0; i < 500; i++)
    {
        printf("\n%f", final_numbers[i]);
    }

    float mean = sum/(float)500;

    printf("\nThe mean of the sample is %f", mean);

    float deviation[500], deviation_sum = 0;

    for (int i = 0; i < 500; i++)
    {
        deviation[i] = final_numbers[i] - mean;
        deviation_sum += pow(deviation[i], 2);
    }
    
    float standard_deviation = deviation_sum / (float)500;

    printf("\nThe standard deviation of the sample is %f", standard_deviation);

    int count = 0;

    for (int i = 0; i < 500; i++)
    {
        if (final_numbers[i] < mean + standard_deviation && final_numbers[i] > mean - standard_deviation)
        {
            count++;
        }
    }
    
    printf("\n%f %% of total 500 observations are lying between (mean - standard_deviation) and (mean + standard_deviation).", (float)count/(float)5);
    
    return 0;
}