#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// Question :: Write a program in C to generate N no. of exponentially distributed random numbers.Calculate sample mean and variance and compare with population parameters.

int main()
{
    int n;
    printf("\nEnter desired sample size = ");
    scanf("%d", &n);

    float lambda;
    printf("\nEnter Lambda = ");
    scanf("%f", &lambda);

    float random[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        random[i] = rand()/(float)RAND_MAX;
    }
    
    printf("\nThe random sample generated is::\n");
    for (int i = 0; i < n; i++)
    {
        random[i] = -(1/lambda) * ( log(1-random[i]) );
        printf("%f\n", random[i]);
    }

    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + random[i];
    }
    
    float mean = sum/(float)n;
    printf("\nThe sample mean is %f", mean);

    printf("\nPopulation Mean = %f", (1/lambda));


    float deviation[n];
    for (int i = 0; i < n; i++)
    {
        deviation[i] = (random[i] - mean) * (random[i] - mean);
    }
    

    float total_deviation = 0;
    for (int i = 0; i < n; i++)
    {
        total_deviation = total_deviation + deviation[i];
    }

    printf("\nThe sample variance is %f", total_deviation/(float)n);
    
    printf("\nThe population variance is %f", (1/(lambda*lambda)) );
    
    
return 0;
}