#include<stdio.h>

int main()
{
    float celsius, fahrenheit;
    int lower = 0, upper = 100, step = 10;
    
    celsius = lower;
    printf("  C    F\n");
    while (celsius <= upper)
    {
        fahrenheit = ((9*celsius)/5) + 32;
        printf("%3.0f  %3.0f\n", celsius, fahrenheit);
        celsius += step;
    }
    
    return 0;
}