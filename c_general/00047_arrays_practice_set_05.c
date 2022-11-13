#include<stdio.h>

//reversing an array

int main(){
    int n;
    printf("Enter your array length n = \n");
    scanf("%d", &n);

    int array1[n];
    int i;
    for (int i = 0; i < n; i++)
    {
        printf("Enter array1[%d] = \n", i);
        scanf("%d", &array1[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", array1[i]);
    }
    printf("\n");
    
    
    int array2[n];
    
    for (int i = 0; i <= (n-1); i++)
    {
        array2[i] = array1[(n-1)-i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", array2[i]);
    }
    
    
    
    return 0;
}