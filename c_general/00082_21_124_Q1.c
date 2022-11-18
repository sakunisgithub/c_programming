#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// Question :: Write a program in C to generate N no. of uniformly distributed random numbers in (a,b) and store them in a data file.

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
    pointer = fopen("00082_21_124_Q1_output.dat", "w");
    FILE *pointer1 = NULL;
    pointer1 = fopen("00082_21_124_data_set.dat", "w"); // we are creating this extra data set file so that for future purposes we can easily call data from this set
    FILE *pointer2 = NULL;
    pointer2 = fopen("00082_21_124_data_set_copy.dat", "w"); // we are creating yet another extra data set file so that for future purposes we can easily call data from this set
    // but why another data set?? because, from one data set we shall count the number of numbers using fgetchar function and from the other data set file we shall scan the numbers using fscanf function. 
    // I previously created only one data file and used it to count and scan the numbers. It did count the number of numbers correctly, but later it failed to scan the numbers after fgetchar was once applied. I don't know what exactly is the problem.
    fprintf(pointer, "Sample Size = %d\n", n);
    fprintf(pointer, "Parameter a = %f\n", a);
    fprintf(pointer, "Parameter b = %f\n", b);
    fprintf(pointer, "The random sample generated is::\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(pointer, "%f\n",value[i]);
        fprintf(pointer1, "%f\n",value[i]);
        fprintf(pointer2, "%f\n",value[i]);
    }
    fclose(pointer);
    fclose(pointer1);
    
    return 0;
}