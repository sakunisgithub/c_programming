#include<stdio.h>

int main(){
    int n;
    printf("Enter n=");
    scanf("%d", &n);
    int i = 0;
    int sum = 0;
    do
    {
        sum = sum + i;
        i++;
    } while (i<=n);
    printf("The sum of first %d natural numbers is %d",n, sum);
    
    return 0;
}