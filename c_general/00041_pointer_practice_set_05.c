#include<stdio.h>

// printing the value of one variable using pointer to pointer variable

int main(){
    int i = 5;
    int* j = &i;
    int** k = &j;
    printf("The value of the variable i is %d", *(*(k)));
    return 0;
}