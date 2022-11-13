#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    printf("\nEnter the number of unique observations = ");
    scanf("%d", &n);

    float observations[n], frequency[n], product, total_product = 0, total_frequency = 0;

    printf("\nEnter the observations and their corresponding frequencies ::: \n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter observation[%d] = ", i+1);
        scanf("%f", &observations[i]);
        printf("\nEnter frequency[%d] = ", i+1);
        scanf("%f", &frequency[i]);
        product = observations[i] * frequency[i];
        total_product += product;
        total_frequency += frequency[i];
    }

    // evaluating the mean
    float mean = total_product / total_frequency;

    // calculating the deviations
    float deviation[n], numerator_for_moment_order_2 = 0, numerator_for_moment_order_3 = 0, numerator_for_moment_order_4 = 0;
    for (int i = 0; i < n; i++)
    {
        deviation[i] = observations[i] - mean;
        numerator_for_moment_order_2 += ( (pow(deviation[i], 2) ) * frequency[i] );
        numerator_for_moment_order_3 += ( (pow(deviation[i], 3) ) * frequency[i] );
        numerator_for_moment_order_4 += ( (pow(deviation[i], 4) ) * frequency[i] );
    }

    // evaluating the moments
    float moment_order_2 = numerator_for_moment_order_2 / total_frequency;
    float moment_order_3 = numerator_for_moment_order_3 / total_frequency;
    float moment_order_4 = numerator_for_moment_order_4 / total_frequency;

    // evaluating measure of skewness
    float measure_of_skewness = pow(moment_order_3, 2) / pow(moment_order_2, 3);
    printf("\nMeasure of Skewness(b_1) = %f", measure_of_skewness);

    // evaluating measure of kurtosis
    float measure_of_kurtosis = moment_order_4 / pow(moment_order_2, 2);
    printf("\nMeasure of Kurtosis(b_2) = %f",measure_of_kurtosis);
    
    
    return 0;
}