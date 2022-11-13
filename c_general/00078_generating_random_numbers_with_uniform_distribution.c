#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// generating random numbers with U(0,1)
int main()
{
    int size; 
    printf("\nEnter Sample Size = ");
    scanf("%d", &size);

    float value[size];

    srand(time(NULL));
    
    for (int i = 0; i < size; i++)
    {
        value[i] = rand()/(float)RAND_MAX;    
    }
    
    printf("\nThe random sample generated is::\n");

    for (int i = 0; i < size; i++)
    {
        printf("%f\n", value[i]);
    }
    
    return 0;
}