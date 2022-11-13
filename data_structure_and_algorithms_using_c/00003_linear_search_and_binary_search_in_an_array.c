#include<stdio.h>

void display_array(int *, int);

int linear_search(int *, int, int);

int binary_search(int *, int, int);

void bubble_sort(int*, int);

void swap(int*, int*);

int main()
{
    int array[10] = {10, 21, 93, 42, 85, 63, 67, 48, 59, 14};

    int size = sizeof(array)/sizeof(int);
    
    printf("\nThe array is : ");
    display_array(array, size);

    int number;
    printf("\nEnter the number you want to search = ");
    scanf("%d", &number);

    // linear search
    int linear_search_code = linear_search(array, size, number);
    (linear_search_code == -1) ? (printf("\n[By Linear Search] Number not found !")) : (printf("\n[By Linear Search] Number found at index %d", linear_search_code));

    // binary search
    bubble_sort(array, size);
    printf("\nThe sorted array is : ");
    display_array(array, size);
    int binary_search_code = binary_search(array, size, number);
    (binary_search_code == -1) ? (printf("\n[By Binary Search] Number not found !")) : (printf("\n[By Binary Search] Number found at index %d", binary_search_code));

    return 0;
}

void display_array(int *A, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", *(A + i));
    }
    
}

int linear_search(int *A, int array_size, int number_to_search)
{
    int i;

    for (i = 0; i < array_size; i++)
    {
        if (number_to_search == *(A + i))
        {
            break;
        }
    }

    if (i == array_size)
    {
        return -1;
    }
    else
    {
        return i;
    }
    
}

int binary_search(int *A, int array_size, int number_to_search)
{
    int low = 0, high = array_size - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (number_to_search == *(A + mid))
        {
            return mid;
        }
        else if (number_to_search < *(A + mid))
        {
            high = mid - 1;
        }
        else if (number_to_search > *(A + mid))
        {
            low = mid + 1;
        }
    }

    return -1;
    
}

void bubble_sort(int* A, int a)
{
    for (int i = 0; i < a-1; i++)
    {
        // printf("\nRunning pass number %d", i+1);
        int sort_code = 0;
        for (int j = 0; j < a-1-i; j++)
        {
            if ( *(A+j) > *(A+j+1) )
            {
                swap( (A+j), (A+j+1));
                sort_code = 1;
            }
        }
        if (sort_code == 0)
        {
            break;
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