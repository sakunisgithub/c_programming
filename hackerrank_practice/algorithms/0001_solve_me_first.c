#include<stdio.h>

int solveMeFirst(int, int);

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    printf("%d", solveMeFirst(a, b));

    return 0;
}

int solveMeFirst(int num1, int num2)
{
    return num1+num2; 
}