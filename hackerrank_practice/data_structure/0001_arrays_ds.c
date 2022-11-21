#include<stdio.h>

void reverse_array(int *, int);

void swap(int *, int *);

int main()
{
    int length;
    scanf("%d", &length);

    int array[length];

    for (int i = 0; i < length; i++)
    {
        scanf("%d", &array[i]);
    }

    reverse_array(array, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", *(array + i));
    }
    
    return 0;
}

void reverse_array(int * A, int array_length)
{
    for (int i = 0; i < array_length/2; i++)
    {
        swap((A + i), (A + array_length - 1 -i));
    }
}

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}