#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int main()
{
    int n;
    float lmd;
    printf("\nEnter Sample Size = ");
    scanf("%d", &n);
    printf("\nEnter parameter Lambda = ");
    scanf("%f", &lmd);

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
        value[i] = -(1/lmd) * ( log(1-random[i]) );
        printf("%f\n", value[i]);
    }

    FILE *pointer = NULL;
    pointer = fopen("00080_output.dat", "w");
    fprintf(pointer, "Sample Size = %d\n", n);
    fprintf(pointer, "Parameter Lambda = %f\n", lmd);
    fprintf(pointer, "The random sample generated is::\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(pointer, "%f\n", value[i]);
    }
    fclose(pointer);
    
    
    return 0;
}