#include<stdio.h>
// detecting a number is prime or not using for loop
int main(){
    int n, m;
    printf("Enter n=");
    scanf("%d", &n);
    for (int i = 2; i < n; i++)
    {
        m = n%i;
        if (m==0)
        {break;} 
    }
    if (m==0)
    {
        printf("%d is not a prime number", n);
    }
    else
        {
            printf("%d is a prime number", n);
        }
    
    return 0;
}