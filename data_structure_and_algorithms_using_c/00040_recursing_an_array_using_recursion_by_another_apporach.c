#include<stdio.h>

void print_array(int *, int);

void reverse_array(int *, int, int);

void swap(int *, int *);

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};

    print_array(array, 8);

    reverse_array(array, 8, 0);

    print_array(array, 8);

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

void reverse_array(int * A, int n, int index)
{
    if (index >= n/2)
    {
        return;
    }
    else
    {
        swap((A + index), (A + n - index - 1));
        reverse_array(A, n, index + 1);
    }
}

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}