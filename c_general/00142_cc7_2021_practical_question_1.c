#include<stdio.h>
#include<math.h>

#define f(x) (1 - x + 2*(x*x) + 3*(x*x*x)) // the given function
#define f1(x) (-1 + 4*x + 9*(x*x)) // first order derivative
#define f2(x) (4 + 18*(x)) // second order derivative

int main()
{
    float x;

    printf("Enter the value of x = ");
    scanf("%f", &x);

    printf("\nf(%f) = %f\n", x, f(x));
    printf("\nf'(%f) = %f\n", x, f1(x));
    printf("\nf''(%f) = %f\n", x, f2(x));

    float x_initial = -1.10;

    float x_values[1000];
    x_values[0] = x_initial;

    for (int i = 1; i < 1000; i++)
    {
        x_values[i] = x_values[i-1] - ( f1(x_values[i-1]) / f2(x_values[i-1]) );

        float difference = fabs(x_values[i] - x_values[i-1]);

        if (difference < 0.0001)
        {
            printf("\nThe required root of the given equation is %f\n", x_values[i]);
            break;
        }
        
    }
    
    return 0;
}