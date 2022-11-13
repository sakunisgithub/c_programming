#include<stdio.h>

void display_array(int *, int);

int delete_element(int *, int *, int);

int main()
{
    int array[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int used_size = 10;
    
    printf("\nCurrent array is : ");
    display_array(array, used_size);

    int index;
    printf("\nEnter the index(0-%d) of the element you want to delete = ", used_size-1);
    scanf("%d", &index);

    int code;
    (index < 0 || index > used_size - 1) ? (printf("\nInvalid input !")) : (code = delete_element(array, &used_size, index));

    if (code == 1)
    {
        printf("\nDeletion successful !");
        printf("\nThe updated array is : ");
        display_array(array, used_size);
    }
    
    return 0;
}

void display_array(int *A, int array_used_size)
{
    for (int i = 0; i < array_used_size; i++)
    {
        printf("%d ", *(A+i));
    }
    
}

int delete_element(int *A, int *used_length, int element_index)
{
    for (int i = element_index; i < (*(used_length) - 1); i++)
    {
        *(A + i) = *(A + i + 1);
    }
    
    *(used_length) -= 1;

    return 1;
}