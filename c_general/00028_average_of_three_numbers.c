#include<stdio.h>

float average(int, int, int);
int a,b,c;
int main(){
    printf("Enter the value of a\n");
    scanf("%d", &a);
    printf("Enter the value of b\n");
    scanf("%d", &b);
    printf("Enter the value of c\n");
    scanf("%d", &c);
    printf("The average of %d, %d, %d is %f",a, b, c, average(a,b,c));
    return 0;
}

float average(int a, int b, int c)
{
    return (a+b+c)/3.0;
}