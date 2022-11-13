#include<stdio.h>

int main()
{
    int n;
    printf("Enter your array size : ");
    scanf("%d", &n);

    int array[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Array Element[%d] = ", i+1);
        scanf("%d", &array[i]);
    }
    
    int max = array[0];

    for (int i = 1; i < n; i++)
    {
        if (max <= array[i])
        {
            max = array[i];
        }
        
    }

    int min = array[0];

    for (int i = 1; i < n; i++)
    {
        if (min >= array[i])
        {
            min = array[i];
        }
        
    }
    

    printf("\nThe maximum element in the array is %d", max);
    
    printf("\nThe minimum element in the array is %d", min);

    return 0;
}