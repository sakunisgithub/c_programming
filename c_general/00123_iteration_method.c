#include<stdio.h>
#include<math.h>
#define f(x) pow(4-x,1/x)
int main()
{
    double x_values[10000];
    printf("\nEnter the initial value of x[0] = ");
    scanf("%lf", &x_values[0]);

    double difference;
    for (int i = 1; i < 10000; i++)
    {
        x_values[i] = f(x_values[i-1]);
        printf("\nx[%d] = %lf", i, x_values[i]);
        difference = fabs(x_values[i] - x_values[i-1]);
        if (difference < 0.000001)
        {
            printf("\nThe root is %lf", x_values[i]);
            break;
        }
        
    }
    
    return 0;
}