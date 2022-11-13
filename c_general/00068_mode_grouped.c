#include<stdio.h>
// the maximum frequency must not be repeated
int main()
{
    int n;
    printf("Enter total number of classes : ");
    scanf("%d", &n);

    int index; // index will store the index of the maximum frequency in the frequency array
    // the first class is supposed to not have the maximum frequency
    // if the first class has the maximum frequency, the formula will not stand
    float lower[n], upper[n], frequency[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nClass Number : %d :: Enter lower class boundary = ", i+1);
        scanf("%f", &lower[i]);
        fflush(stdin);

        printf("\nClass Number : %d :: Enter upper class boundary = ", i+1);
        scanf("%f", &upper[i]);
        fflush(stdin);

        printf("\nClass Number : %d :: Enter frequency = ", i+1);
        scanf("%f", &frequency[i]);
        fflush(stdin);
    }
    
    float greatest = frequency[0];
    for (int i = 1; i < n; i++)
    {
        if (greatest <= frequency[i])
        {
            greatest = frequency[i];
            index = i;
        }
    }

    float B, C;

    B = ( upper[index] - lower[index] ) * ( frequency[index] - frequency[index-1] );

    C = 2*frequency[index] - frequency[index-1] - frequency[index+1];

    printf("\nMode = %f", ( lower[index] + (B/C) ) );
    
    
    return 0;
}