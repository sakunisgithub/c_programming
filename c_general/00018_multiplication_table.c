#include<stdio.h>

int main(){
    int m, n;
    printf("Enter n=");
    scanf("%d", &n);
    for (int i = 1; i <= 10; i++)
    {
        m = n*i;
        printf("%d x %d = %d\n",n, i, m);
    }
    
    return 0;
}