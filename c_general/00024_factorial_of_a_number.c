#include<stdio.h>

int main(){
    int n ;
    printf("Enter n=");
    scanf("%d", &n);
    int product = 1;
    for (int i = 1; i <= n; i++)
    {
        product = product*i;
    }
    printf("%d!=%d",n, product);
    
    return 0;
}