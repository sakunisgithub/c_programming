#include<stdio.h>

void print_array(int *, int);

void selection_sort(int *, int);

void swap(int *, int *);

int main()
{
    int array[] = {10, 3, 17, 11, 25, 28, 23, 1};

    print_array(array, 8);

    selection_sort(array, 8);

    print_array(array, 8);
    return 0;
}

void print_array(int * A, int array_length)
{
    printf("The array is ::: ");
    for (int i = 0; i < array_length; i++)
    {
        printf("%d ", *(A + i));
    }
    
    printf("\n");
}

void selection_sort(int * A, int array_length)
{
    for (int i = 0; i < array_length - 1; i++)
    {
       for (int j = i+1; j < array_length; j++)
       {
            if (*(A + i) > *(A + j))
            {
                swap((A + i), (A + j));
            }
       }
    }
}

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}