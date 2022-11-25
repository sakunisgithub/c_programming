#include<stdio.h>

void print_array(int *, int);

void quick_sort(int *, int, int);

int partition(int *, int, int);

void swap(int *, int *);

int main()
{
    int array[] = {9, 4, 4, 8, 7, 5, 6};

    int array_size = 7;

    print_array(array, array_size);
    
    quick_sort(array, 0, array_size - 1);

    print_array(array, array_size);

    return 0;
}

void print_array(int * array, int array_length)
{
    printf("The array is ::: ");
    for (int i = 0; i < array_length; i++)
    {
        printf("%d ", *(array + i));
    }

    printf("\n");
}

void quick_sort(int * array, int low, int high)
{
    int partition_index;

    if (low < high)
    {
        partition_index = partition(array, low, high);

        quick_sort(array, low, partition_index - 1);
        quick_sort(array, partition_index + 1, high);
    }

}

int partition(int * array, int low, int high)
{
    int pivot = *(array + low);
    int i = low + 1;
    int j = high;

    do
    {
        while (*(array + i) <= pivot && i <= high)
        {
            i++;
        }

        while (*(array + j) > pivot && j >= low)
        {
            j--;
        }

        if (i < j)
        {
            swap((array + i), (array + j));
        }
        
    } while (i < j);
    
    swap((array + low), (array + j));

    return j;
}

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}