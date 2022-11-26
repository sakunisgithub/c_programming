#include<stdio.h>

void print_array(int *, int);

void merge_sort(int *, int, int);

void merge(int *, int, int, int);

int main()
{
    int array[] = {2, 1, 10, 9, 4, 5, 3, 11};

    int size = 8;

    print_array(array, size);

    merge_sort(array, 0, size - 1);

    print_array(array, size);

    return 0;
}

void print_array(int * array, int array_size)
{
    printf("The array is ::: ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", *(array + i));
    }

    printf("\n");
}

void merge_sort(int * array, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);

        merge(array, low, high, mid);
    }
     
}

void merge(int * array, int low, int high, int mid)
{
    int i = low, j = mid + 1, k = low;

    int new_array[high+1];

    while (i <= mid && j <= high)
    {
        if (*(array + i) < *(array + j))
        {
            *(new_array + k) = *(array + i);
            i++;
            k++;
        }
        else
        {
            *(new_array + k) = *(array + j);
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        *(new_array + k) = *(array + i);
        i++;
        k++;
    }

    while (j <= high)
    {
        *(new_array + k) = *(array + j);
        j++;
        k++;
    }
    
    for (int i = low; i <= high; i++)
    {
        *(array + i) = *(new_array + i);
    }
}