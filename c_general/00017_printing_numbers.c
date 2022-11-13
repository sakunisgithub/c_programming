#include<stdio.h>
// printing first n natural numbers in decreasing order using for loop
int main(){
    int n;
    printf("Enter n=");
    scanf("%d", &n);
    for (int i = n; i > 0; i--)
    {
        printf("%d\n", i);
    }
    
    return 0;
}