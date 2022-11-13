#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int size;
    printf("\nEnter Sample Size = ");
    scanf("%d", &size);

    float value[size], sum = 0.0;

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        value[i] = rand()/(float)RAND_MAX;
        sum = sum + value[i];
    }

    printf("\nThe random sample generated is::\n");
    for (int i = 0; i < size; i++)
    {
        printf("%f\n", value[i]);
    }
    
    printf("\nSample Mean = %f", sum/(float)size);
    printf("\nPopulation Mean = 0.5");
    
    
return 0;
}