#include<stdio.h>

int main()
{
    int n;
    printf("Enter the total number of classes : ");
    scanf("%d", &n);

    float lower[n], upper[n], frequency[n], cumulative_frequency[n];
    float total_frequency, N, median;
    int index; // index refers to the index of the median class

    for (int i = 0; i < n; i++)
    {
        printf("\nClass number : %d :: Enter lower class boundary = ", i+1);
        scanf("%f", &lower[i]);
        fflush(stdin);

        printf("\nClass number : %d :: Enter upper class boundary = ", i+1);
        scanf("%f", &upper[i]);
        fflush(stdin);

        printf("\nClass number : %d :: Enter frequency = ", i+1);
        scanf("%f", &frequency[i]);
        fflush(stdin);
    }
    
    cumulative_frequency[0] = frequency[0];

    for (int i = 1; i < n; i++)
    {
        cumulative_frequency[i] = frequency[i] + cumulative_frequency[i-1];
    }
    
    total_frequency = cumulative_frequency[n-1];

    N = total_frequency/2.0;

    for (int i = 0; i < n; i++)
    {
        if (  (cumulative_frequency[i] == N) || (cumulative_frequency[i] > N)  )
        {
            index = i; // index refers to the index of the median class
            break;
        }
        
    }

    printf("\n");
    printf("Lower Class Boundary \t Upper Class Boundary \t Frequency \t Less than type cumulative frequency\n");

    for (int i = 0; i < n; i++)
    {
        if (i == index)
        {
            printf("%f           \t %f           \t %f             %f:: Median Class\n", lower[i], upper[i], frequency[i], cumulative_frequency[i]);
        }
        else
        {
            printf("%f           \t %f           \t %f           %f\n", lower[i], upper[i], frequency[i], cumulative_frequency[i]);
        }
        
    }
    

    median = lower[index] + ( ( ( N - cumulative_frequency[index-1] ) * ( upper[index] - lower[index] ) ) / frequency[index] );

    printf("\nMedian = %f", median);
    
    return 0;
}