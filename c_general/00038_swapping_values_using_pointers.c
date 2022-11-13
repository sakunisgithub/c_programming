#include<stdio.h>

void swap(int*, int*);
int x, y;

int main()
{
    printf("Enter x = ");
    scanf("%d", &x);
    printf("Enter y = ");
    scanf("%d", &y);

    printf("The values of x and y before swapping are %d and %d respectively.\n", x, y);
    swap(&x, &y);
    printf("The values of x and y after swapping are %d and %d respectively.\n", x, y);
    return 0;
}
void swap(int* a, int*b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}