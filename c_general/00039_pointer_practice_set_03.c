#include<stdio.h>

// Multiplying the input value by 10 and printing output by using pointers and user defined functions

void multiplier(int*);
int x;

int main(){
    printf("Enter the inital value\n");
    scanf("%d", &x);
    multiplier(&x);
    printf("The output value is %d", x);
    return 0;
}

void multiplier(int* a)
{
    *a = (*a)*10;
}