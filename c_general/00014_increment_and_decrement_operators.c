#include<stdio.h>

int main(){
    
    int i = 0;
    
    printf("%d\n", i++);
    // i++ first prints i and then increases i
    printf("%d\n", ++i);
    // ++i first increases i and then prints i
    i++;
    printf("%d\n", i);
    i--;
    printf("%d\n", i);
    --i;
    printf("%d", i);
    return 0;
}