#include<stdio.h>
// print from n to 0
int main(){
    
    int n;
    printf("Enter n=");
    scanf("%d", &n);
    int i = n;
    while (i>=0)
    {
        printf("%d\t", i);
        /* to print vertically use
        printf("%d\n", i); */
        i = i - 1;
    }
    
    return 0;
}