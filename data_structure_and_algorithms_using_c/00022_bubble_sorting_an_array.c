#include<stdio.h>

void print_array(int *, int);

void bubble_sort(int *, int);

void swap(int *, int *);

int main()
{
    int array[] = {4, 3, 10, 15, 13, 23, 20, 6};

    print_array(array, 8);

    bubble_sort(array, 8);

    print_array(array, 8);

    return 0;
}

void print_array(int * A, int array_size)
{
    printf("The array is :: ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", *(A + i));
    }

    printf("\n");
}

void bubble_sort(int * A, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int sort_code = 0;

        for (int j = 0; j < length - 1 - i; j++)
        {
            if (*(A + j) > *(A + j + 1))
            {
                swap((A + j), (A + j + 1));
                sort_code = 1;
            }
        }

        if (sort_code == 0)
        {
            break;
        }
    }
}

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}