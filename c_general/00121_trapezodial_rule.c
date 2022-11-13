#include<stdio.h>

int main()
{
    int n;
    printf("\nEnter the number of intervals = ");
    scanf("%d", &n);

    float lower,upper;
    printf("\nEnter the lower limit = ");
    scanf("%f", &lower);
    printf("\nEnter the upper limit = ");
    scanf("%f", &upper);

    float y_values[n+1];
    printf("\nEnter the values of the function ::: \n");
    for (int i = 0; i <= n; i++)
    {
        printf("\nEnter y[%d] = ", i);
        scanf("%f", &y_values[i]);
    }

    float h = (upper - lower) / n;
    float sum = 0;
    for (int i = 1; i <= n-1; i++)
    {
        sum += y_values[i];
    }

    float area = h * ( ( (y_values[0] + y_values[n]) /2) + sum);
    
    printf("\nThe value of the integral is %f", area);
    
    return 0;
}