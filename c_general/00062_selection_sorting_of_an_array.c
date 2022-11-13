#include<stdio.h>
// selection sorting an array without using functions
int main(){
    int n;
    printf("Enter number of elements you want to enter in the array\n");
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter array[%d]\n", i);
        scanf("%d", &array[i]);
    }
    printf("The initial array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (array[i]> array[j])
            {
                int temp;
                temp = array[i] ;
                array[i] = array[j];
                array[j] = temp;
            }
            
        }
        
    }
    printf("The final array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", array[i]);
    }
    
    
    
    return 0;
}