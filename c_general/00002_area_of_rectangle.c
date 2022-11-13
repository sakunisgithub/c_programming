#include<stdio.h>

int main(){
    
    int a;
    int b;
    printf("Enter the integer length of the rectangle\n");
    scanf("%d", &a);

    printf("Enter the integer breadth of the rectangle\n");
    scanf("%d", &b);

    printf("The area of the rectangle is %d square units", a*b );
    
    return 0;
}