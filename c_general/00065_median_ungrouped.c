#include<stdio.h>

void display(float*, int);

void bubble_sort(float*, int);

void swap(float*, float*);

int main()
{
    int n;
    printf("Enter total number of observations = ");
    scanf("%d", &n);

    float array[n], median;

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter observation no %d = ", i+1);
        scanf("%f", &array[i]);
    }

    printf("\n");

    printf("The observations are as follows.\n");
    display(array, n);

    bubble_sort(array, n);

    printf("\n");

    printf("The observations arranged in ascending order are as follows.\n");
    display(array, n);

    if (n%2 == 0)
    {
        printf("\nMedian = %f", ( array[(n/2)-1] + array[(n/2)] )/2.0 );
    }
    else
    {
        printf("\nMedian = %f", array[((n+1)/2)-1] );
    }

    return 0;
}

void display(float* A, int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("%f\n", *(A+i));
    }
    
}

void bubble_sort(float* A, int a)
{
    for (int i = 0; i < a-1; i++)
    {
        int sort_code = 0;
        for (int j = 0; j < a-1-i; j++)
        {
            if ( *(A+j) > *(A+j+1) )
            {
                swap( (A+j), (A+j+1) );
                sort_code = 1;
            }
            
        }
        if (sort_code == 0)
        {
            break;
        }
    }
}

void swap(float* x, float* y)
{
    float temp;
    temp = *x;
    *x = *y;
    *y = temp;
}