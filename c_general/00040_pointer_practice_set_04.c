#include<stdio.h>

// Calculating sum and average of two numbers using pointers and user defined functions

void sum(float*, float*);
void average(float*, float*);
float x, y, s, avg;

int main(){
    printf("Enter Your First Number\n");
    scanf("%f", &x);
    printf("Enter Your Second Number\n");
    scanf("%f", &y);

    sum(&x, &y);
    printf("The sum of %f and %f is %f\n", x, y, s);
    
    average(&x, &y);
    printf("The average of %f and %f is %f\n", x, y, avg);

    return 0;
}

void sum(float* a, float* b)
{
    s = *a + *b;
}

void average(float* a, float*b)
{
    avg = (*a+*b)/2.0;
}