#include<stdio.h>
// printing first n natural numbers in increasing order using for loop
int main(){
    int n, i;
    printf("Enter n=");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("%d\n", i);
    }
    
    return 0;
}