#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    printf("\nEnter the order of the binomial distribution = ");
    scanf("%d", &n);

    int alpha = n + 1; // because in a binomial distribution x = 0(1)n So we shall need arrays of size n+1

    FILE* pointer = NULL;
    pointer = fopen("binomial_fitting.dat", "w");

    int value[alpha], frequency[alpha];
    printf("\nEnter values of x and corresponding frequencies:::\n");
    for (int i = 0; i < alpha; i++)
    {
        printf("\nEnter value[%d] = ", i+1);
        scanf("%d", &value[i]);
        printf("\nEnter frequency[%d] = ", i+1);
        scanf("%d", &frequency[i]);
    }

    int total_frequency = 0, fx[alpha], total_fx = 0;
    for (int i = 0; i < alpha; i++)
    {
        fx[i] = value[i] * frequency[i]; // counting fx
        total_fx = total_fx + fx[i]; // counting total fx
        total_frequency = total_frequency + frequency[i]; // counting total frequency
    }

    float mean = (float)total_fx / (float)total_frequency;

    float p, q;
    

    p = mean / (float)n;
    q = 1 - p;
    float A = p/q;
    
    // calculating ( ((n-x)/(x+1)) * (p/q) )
    float factor[alpha-1];
    for (int i = 0; i < alpha-1; i++)
    {
        factor[i] = ( ( ((float)n - (float)value[i])/((float)value[i] + 1) ) * A );
    }
    
    // calculating the expected frequencies

    float expected_frequency[alpha];
    expected_frequency[0] = total_frequency * pow(q, n);
    for (int i = 1; i < alpha; i++)
    {
        expected_frequency[i] = factor[i-1] * expected_frequency[i-1];
    }

    int approximate_expected_frequency[alpha];
    for (int i = 0; i < alpha; i++)
    {
        if ( (expected_frequency[i] - floor(expected_frequency[i]) ) >= 0.5 )
        {
            approximate_expected_frequency[i] = floor(expected_frequency[i]) + 1;
        }
        else
        {
            approximate_expected_frequency[i] = floor(expected_frequency[i]);
        }
        
    }

    fprintf(pointer,"\nCOMPUTATION OF EXPECTED BINOMIAL FREQUENCIES\n");
    fprintf(pointer,"\n--------------------------------------------\n");
    fprintf(pointer,"\n\nValues(x)  Observed Frequencies \tfx \t  \t (n-x)p/(x+1)q \t \t Expected Frequencies\n");
    for (int i = 0; i < alpha-1; i++)
    {
        fprintf(pointer,"\n%5d \t \t %5d \t \t \t %8d   \t \t %4f \t \t %4f = ~ %5d\n", value[i], frequency[i], fx[i], factor[i], expected_frequency[i], approximate_expected_frequency[i]);
    }
    fprintf(pointer,"\n%5d \t \t %5d \t \t \t %8d   \t \t            \t %4f = ~ %5d\n", value[n], frequency[n], fx[n], expected_frequency[n], approximate_expected_frequency[n]);
    
    fclose(pointer);
    
    
    
    return 0;
}