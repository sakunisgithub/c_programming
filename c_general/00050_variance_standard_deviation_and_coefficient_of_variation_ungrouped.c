#include<stdio.h>
#include<math.h>

int main()
{
    int n ;
    float mean, deviation, standard_deviaton;
    float sum = 0;
    printf("Enter total number of observations : \n");
    scanf("%d", &n);
    float observation[n];
    for (int i = 0; i < n ; i++)
    {
        printf("Enter observation[%d] : \n", i);
        scanf("%f", &observation[i]);
        sum = sum + observation[i];
    }
    mean = sum/n;
    printf("The mean of the observations is %f\n", mean);

    for (int i = 0; i < n; i++)
    {
        deviation = deviation + ((observation[i]- mean) * (observation[i]- mean));
    }
    printf("The variance of the observations is %f\n", deviation/n);

    standard_deviaton = sqrt(deviation/n);

    printf("The standard deviation of the observations is %f\n", standard_deviaton);

    printf("The Coefficient of Variation of the observations is %f\n", (standard_deviaton/mean)*100);
       
}