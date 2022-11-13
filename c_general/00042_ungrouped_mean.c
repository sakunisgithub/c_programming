#include<stdio.h>

// Asking the user the total number of observations

int main(){
    
    int n ;
    float sum = 0 ;

    printf("Enter total number of observations = ");
    scanf("%d", &n);

    float observation[n];
    
    for (int i = 1; i <= n; i++)
    {
        printf("Enter observation[%d] = ", i);
        scanf("%f", &observation[i]);
        sum = sum + observation[i];
    }

    printf("The mean of the observations is %f", (sum/n));
    
    return 0;
}