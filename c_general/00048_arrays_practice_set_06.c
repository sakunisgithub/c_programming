#include<stdio.h>

// counting number of positive integers in an array

int counter(int*, int);
int i, n, number = 0;

int main(){

    printf("Enter the length of your array : ");
    scanf("%d", &n);

    printf("\n");

    int array[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter your integer : array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    printf("\n");
    
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }

    printf("\n");
    
    counter(&array[i], i);

    printf("Number of positive integers present is %d", number);

    return 0;
}

int counter(int* a, int b)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            number++;
        }
    }
}