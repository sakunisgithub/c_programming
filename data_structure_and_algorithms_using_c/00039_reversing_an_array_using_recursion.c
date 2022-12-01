#include<stdio.h>

void print_array(int *, int);

void reverse_array(int *, int, int);

void swap(int *, int *);

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};

    print_array(array, 7);

    reverse_array(array, 0, 6);

    print_array(array, 7);

    return 0;
}

void print_array(int * A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(A + i));
    }

    printf("\n");
}

void reverse_array(int * A, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    else
    {
        swap((A + low), (A + high));
        reverse_array(A, low + 1, high - 1);
    }
    
}

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}