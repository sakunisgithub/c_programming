#include<stdio.h>

int main()
{
    int n;
    printf("\nEnter the number of intervals(must be an even number) = ");
    scanf("%d", &n);

    float lower, upper;
    printf("\nEnter the lower limit = ");
    scanf("%f", &lower);
    printf("\nEnter the upper limit = ");
    scanf("%f", &upper);

    float y_values[n+1];
    printf("\nEnter the values of y :::\n");
    for (int i = 0; i <= n; i++)
    {
        printf("\nEnter y[%d] = ", i);
        scanf("%f", &y_values[i]);
    }

    float h = (upper - lower) / n;
    
    float A = y_values[0] + y_values[n];

    float B = 0, C = 0;
    for (int i = 1; i <= n-1; i++)
    {
        if (i % 2 != 0)
        {
            B += y_values[i];
        }
        if (i % 2 == 0)
        {
            C += y_values[i];
        }
        
        
    }

    float area = (h/3) * (A + 4*B + 2*C);

    printf("\nThe value of the integral is %f", area);
    
    return 0;
}