#include<stdio.h>
#include<math.h>
double f(double);
double g(double);

int main()
{
    double x_values[10000];
    printf("\nEnter the approximate value of the root x = ");
    scanf("%lf", &x_values[0]);
    double difference;
    for (int i = 1; i < 10000; i++)
    {
        x_values[i] = x_values[i-1] - ( f(x_values[i-1]) / g(x_values[i-1]) );
        printf("\nx[%d] = %5.15lf", i, x_values[i]);
        difference = fabs(x_values[i] - x_values[i-1]);
        if (difference < 0.000001)
        {
            printf("\nThe required root is %5.15lf", x_values[i]);
            break;
        }
        
    }
    
    return 0;
}

double f(double x)
{
    double result1 = pow(x,3) - 3*x - 5;
    return result1;
}
double g(double x)
{
    double result2 = 3*pow(x,2) - 3;
    return result2;
}