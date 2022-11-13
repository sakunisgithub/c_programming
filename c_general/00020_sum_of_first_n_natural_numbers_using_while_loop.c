#include<stdio.h>

int main(){
    int n;
    printf("Enter n=");
    scanf("%d", &n);
    int i = 1;
    int sum = 0;
    while (i<=n)
    {
        sum = sum + i;
        i++;
    }
    printf("The sum of first %d natural numbers is %d",n, sum);
    return 0;
}