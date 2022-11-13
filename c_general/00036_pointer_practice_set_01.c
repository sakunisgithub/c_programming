#include<stdio.h>

// printing address and value using pointers

int main(){
    int var1 = 36;
    int var2 = 2;
    printf("The address of the variable var is %u\n", &var1);
    printf("The value of the variable var is %d\n", *(&var1));
    printf("The address of the variable var1 is %u\n", &var2);
    printf("The value of the variable var1 is %d\n", *(&var2));
    return 0;
}