#include<stdio.h>

void print_array(int *, int);

void count_sort(int *, int);

int main()
{
    int array[] = {2, 10, 9, 3, 6, 15, 20, 1, 8, 5};

    print_array(array, 10);

    count_sort(array, 10);

    print_array(array, 10);

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

void count_sort(int * array, int array_length)
{
    int max = *(array);

    for (int i = 1; i < array_length; i++)
    {
        if (*(array + i) > max)
        {
            max = *(array + i);
        }
    }
    
    max++;
    int count_array[max];

    for (int i = 0; i < max; i++)
    {
        *(count_array + i) = 0;
    }

    for (int i = 0; i < array_length; i++)
    {
        *(count_array + (*(array + i))) += 1;
    }
    
    int j = 0;

    for (int i = 0; i < max; i++)
    {
        while (*(count_array + i) > 0)
        {
            *(array + j) = i;
            j++;
            *(count_array + i) -= 1;
        }
    }
}