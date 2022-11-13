#include<stdio.h>

int main()
{
    int n;
    printf("\nEnter the set of observations you want to enter = ");
    scanf("%d", &n);

    printf("\nEnter the observations ::: \n");
    float x_values[n], y_values[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter value of x[%d] = ", i+1);
        scanf("%f", &x_values[i]);
        printf("\nEnter value of y[%d] = ", i+1);
        scanf("%f", &y_values[i]);
    }

    float x;
    printf("\nEnter the value of x = ");
    scanf("%f", &x);

    float numerator[n], denominator[n];

    for (int i = 0; i < n; i++)
    {
        numerator[i] = 1;
        denominator[i] = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                numerator[i] *= (x - x_values[j]);
                denominator[i] *= (x_values[i] - x_values[j]);
            }
            
        }
        
    }
    
    float result = 0;
    for (int i = 0; i < n; i++)
    {
        result += ( (numerator[i])/(denominator[i]) ) * y_values[i];
    }
    
    printf("\nThe value of f(%f) is %f", x, result);
    
    return 0;
}