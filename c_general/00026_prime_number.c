#include<stdio.h>
// detecting a number is prime or not using while loop
int main(){
    int m, n;
    printf("Enter n=");
    scanf("%d", &n);
    int i = 2;
    while (i<n)
    {
        m = n%i;
        if (m==0)
        {
            break;
        }
        else {i++;}
    }
    if (m==0)
    {
        printf("%d is not a prime", n);
    }
    else {printf("%d is a prime", n);}
    
    
    return 0;
}