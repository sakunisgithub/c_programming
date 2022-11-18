#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int n;
    float a, b;
    printf("\nEnter Sample Size = ");
    scanf("%d", &n);
    printf("\nEnter parameter a = ");
    scanf("%f", &a);
    printf("\nEnter parameter b = ");
    scanf("%f", &b);

    float random[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        random[i] = rand()/(float)RAND_MAX;
    }

    float value[n];
    printf("\nThe random sample generated is::\n");
    for (int i = 0; i < n; i++)
    {
        value[i] = a + (b - a)*random[i];
        printf("%f\n", value[i]);
    }
    
    FILE *pointer = NULL;
    pointer = fopen("00079_output.dat", "w");
    fprintf(pointer, "Sample Size = %d\n", n);
    fprintf(pointer, "Parameter a = %f\n", a);
    fprintf(pointer, "Parameter b = %f\n", b);
    fprintf(pointer, "The random sample generated is::\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(pointer, "%f\n",value[i]);
    }
    fclose(pointer);
    
    return 0;
}