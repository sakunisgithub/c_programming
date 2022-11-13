#include<stdio.h>
#include<math.h>

float mean(float*, int);

void deviation_from_mean(float*, int, float*, float);

int main()
{
    int n;
    printf("\nEnter the common number of observations of both variables = ");
    scanf("%d", &n);

    float x_observations[n], y_observations[n];

    printf("\nEnter the observations:::\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter x_observation[%d] = ", i+1);
        scanf("%f", &x_observations[i]);
        printf("\nEnter y_observation[%d] = ", i+1);
        scanf("%f", &y_observations[i]);
    }

    float mean_x = mean(x_observations, n);
    float mean_y = mean(y_observations, n);

    float deviation_of_x[n], deviation_of_y[n];

    deviation_from_mean(x_observations, n, deviation_of_x, mean_x);
    deviation_from_mean(y_observations, n, deviation_of_y, mean_y);

    float numerator = 0;
    for (int i = 0; i < n; i++)
    {
        float product_numerator = (*(deviation_of_x+i)) * (*(deviation_of_y+i));
        numerator += product_numerator;
    }

    float element_1 = 0, element_2 = 0;
    for (int i = 0; i < n; i++)
    {
        element_1 += (*(deviation_of_x+i)) * (*(deviation_of_x+i));
        element_2 += (*(deviation_of_y+i)) * (*(deviation_of_y+i));
    }
    
    float denominator = element_1 * element_2;
    denominator = sqrt(denominator);
    

    printf("\nThe Correlation Coefficient is %f", numerator/denominator);
    

    return 0;
}

float mean(float* ARRAY, int array_size)
{
    float sum = 0;
    for (int i = 0; i < array_size; i++)
    {
        sum += *(ARRAY+i);
    }
    
    return sum / (float)array_size;
}

void deviation_from_mean(float* ARRAY, int array_size, float* ARRAY_OUTPUT, float mean)
{
    for (int i = 0; i < array_size; i++)
    {
        *(ARRAY_OUTPUT+i) = *(ARRAY+i) - mean;
    }
    
}