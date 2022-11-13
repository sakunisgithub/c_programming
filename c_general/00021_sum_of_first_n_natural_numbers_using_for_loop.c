#include<stdio.h>

int main(){
    int n;
    printf("Enter n=");
    scanf("%d", &n);
    float sum = 0;
    float avg;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
        avg = sum /n;
    }
    printf("The sum of first %d natural numbers is %d\n",n, sum);
    printf("The average of first %d natural numbers is %f",n, avg);
    
    return 0;
}