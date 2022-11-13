#include<stdio.h>
// detecting a number is prime or not using do while loop
int main(){
    int m,n;
    int i = 2;
    printf("Enter n=");
    scanf("%d", &n);
    do
    {
        m = n%i;
        if (m==0)
        {
            break;
        }
        else{i++;}
        
    } while (i<n);
    if (m==0)
    {
        printf("%d is not a prime number", n);
    }
    else{printf("%d is a prime number", n);}
    
    
    return 0;
}