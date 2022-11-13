#include<stdio.h>

int main(){
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int* ptr = array; //&array[0] == array
    printf("The first element of the array is %d\n", *ptr);
    ptr = ptr + 2;
    printf("The third element of the array is %d", *ptr);
    return 0;
}