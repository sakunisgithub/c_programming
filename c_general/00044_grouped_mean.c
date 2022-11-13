#include<stdio.h>

// Asking the user the total number of classes

int main(){
    int n;
    printf("Enter the total number of classes :\n");
    scanf("%d", &n);

    float lower[n], upper[n], mark[n], frequency[n], product[n], sum = 0, total_frequency = 0;

    for (int i = 1; i <= n; i++)
    {
        printf("Enter lower[%d] = ", i);
        scanf("%f", &lower[i]);

        printf("Enter upper[%d] = ", i);
        scanf("%f", &upper[i]);

        mark[i] = (lower[i] + upper[i])/2.0;

        printf("Enter frequency[%d] = ", i);
        scanf("%f", &frequency[i]);

        total_frequency = total_frequency + frequency[i];

        product[i] = mark[i] * frequency[i];

        sum = sum + product[i];
    }

    printf("The required mean is %f", sum/total_frequency);
    
    return 0;
}