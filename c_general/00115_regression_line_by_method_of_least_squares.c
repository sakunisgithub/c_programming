#include<stdio.h>

int main()
{
    int n;
    printf("\nEnter n = ");
    scanf("%d", &n);

    float value_x[n], value_y[n];
    printf("\nEnter the values of X and Y:::\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter value_x[%d] = ", i+1);
        scanf("%f", &value_x[i]);
        printf("\nEnter value_y[%d] = ", i+1);
        scanf("%f", &value_y[i]);
    }

    float square_x[n], xy[n];
    for (int i = 0; i < n; i++)
    {
        square_x[i] = value_x[i] * value_x[i];
        xy[i] = value_x[i] * value_y[i];
    }
    
    float sum_x = 0, sum_y = 0, sum_square_x = 0, sum_xy = 0;
    for (int i = 0; i < n; i++)
    {
        sum_x += value_x[i];
        sum_y += value_y[i];
        sum_square_x += square_x[i];
        sum_xy += xy[i];
    }

    float slope;
    slope = ( ( ((float)n * sum_xy) - (sum_x * sum_y) ) / ( ((float)n * sum_square_x) - (sum_x * sum_x) ) );
    
    float intercept;
    intercept = ( (sum_y - (slope * sum_x)) / ((float)n) );

    FILE* pointer = NULL;
    pointer = fopen("regression_line_output.dat", "w");

    fprintf(pointer,"NECESSARY CALCULATION FOR FITTING A REGRESSION LINE");
    fprintf(pointer,"\n---------------------------------------------------\n");

    fprintf(pointer,"\t\tX \t\t\t\t  X*X \t\t\t\t \t Y \t\t\t\t \t    \tXY");
    for (int i = 0; i < n; i++)
    {
        fprintf(pointer, "\n\t %f \t\t\t %f \t\t\t %f \t\t\t \t %f\n", value_x[i], square_x[i], value_y[i], xy[i]);
    }
    fprintf(pointer,"\n---------------------------------------------------\n");
    fprintf(pointer, "\n\t %f \t\t %f \t\t\t %f \t\t\t \t %f \t\t\t \t :::::: TOTAL\n", sum_x, sum_square_x, sum_y, sum_xy);

    fprintf(pointer, "\nEquation of fitted regression line is y = (%f)x + (%f)\n", slope, intercept);


    
    return 0;
}