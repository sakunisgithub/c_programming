#include<stdio.h>

// the pattern is 

// *
// **
// ***
// ****
// *****
// for n = 5
int star(int);

int n;

int main(){
    printf("Enter n=");
    scanf("%d", &n);
    star(n);
    return 0;
}

int star(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }        
        printf("\n");
    }
}