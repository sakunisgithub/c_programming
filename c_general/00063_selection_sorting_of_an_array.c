#include<stdio.h>
// selection sorting an array using functions
void display(int*, int);

void selection_sort(int*, int);

void swap(int*, int*);

int main()
{
    int n;
    printf("Enter total number of values you want to enter\n");
    scanf("%d", &n);

    int array[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter array[%d] = ", i+1);
        scanf("%d", &array[i]);
    }
    printf("\n");

    printf("The initial array is\n");
    display(array, n);

    selection_sort(array, n);

    printf("\n");

    printf("The final array is\n");
    display(array, n);

    return 0;
}

void display(int* pointer, int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("%d  ", *(pointer+i));
    }
    
}

void selection_sort(int* pointer, int a)
{
    for (int i = 0; i < a-1; i++)
    {
        for (int j = i+1; j < a; j++)
        {
            if (  (*(pointer+i))  >  (*(pointer+j))  )
            {
                swap(pointer+i, pointer+j);
            }
            
        }
        
    }
    
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}