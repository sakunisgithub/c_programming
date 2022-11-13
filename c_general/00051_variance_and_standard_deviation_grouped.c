#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    float sum = 0, mean, total_frequency = 0, total_deviation = 0, variance;
    printf("Enter total number of classes :\n");
    scanf("%d", &n);

    float lower[n], upper[n], frequency[n], mark[n], product[n], deviation[n];
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter lower class boundary : lower[%d]\n", i);
        scanf("%f", &lower[i]);

        printf("Enter upper class boundary : upper[%d]\n", i);
        scanf("%f", &upper[i]);

        mark[i] = (lower[i] + upper[i])/2.0 ;

        printf("Enter frequency : frequency[%d]\n", i);
        scanf("%f", &frequency[i]);

        product[i] = mark[i] * frequency [i];

        sum = sum + product[i];

        total_frequency = total_frequency + frequency[i];

    }

    mean = sum/total_frequency;

    printf("The mean of the observations is %f\n", mean);

    for (int i = 0; i < n; i++)
    {
        deviation[i] = (frequency[i] * (mark[i] - mean) * (mark[i] - mean));

        total_deviation = total_deviation + deviation[i];
    }

    // printf("The total deviation of the observations is %f\n", total_deviation);

    variance = total_deviation/total_frequency;

    printf("The variance of the observations is %f\n", variance);

    printf("The standard deviation of the observations is %f\n", sqrt(variance));

    printf("The coefficient of variation of the observations is %f\n", (sqrt(variance)/mean)*100);
    
    
return 0;
}