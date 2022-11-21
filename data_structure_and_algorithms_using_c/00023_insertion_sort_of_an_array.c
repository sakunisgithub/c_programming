#include<stdio.h>

void print_array(int *, int);

void insertion_sort(int *, int);

int main()
{
    int array[] = {3, 1, 8, 15, 6, 27, 11, 19};

    print_array(array, 8);

    insertion_sort(array, 8);

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

void insertion_sort(int * A,  int array_length)
{
    int key, j;

    for (int i = 1; i <= array_length - 1; i++)
    {
        key = *(A + i);
        j = i - 1;
        while (j >= 0 && *(A + j) > key)
        {
            *(A + j + 1) = *(A + j);
            j--;
        }

        *(A + j + 1) = key;
    }
    
}