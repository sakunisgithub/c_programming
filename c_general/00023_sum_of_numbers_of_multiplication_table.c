#include<stdio.h>

int main(){
    int m,n;
    printf("Enter n=");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <=10; i++)
    {
        printf("%d X %d = %d\n", n, i, n*i);
        m = n*i;
        sum = sum + m;
    }
    printf("The sum of the resultant numbers occuring in the multiplicity table of %d is %d",n, sum);
    
    return 0;
}