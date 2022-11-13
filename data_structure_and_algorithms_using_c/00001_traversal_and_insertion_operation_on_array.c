#include<stdio.h>

void display(int *, int);

int insert(int *, int *, int, int, int);

int main()
{
    int array[100] = {7, 183, 134, 148, 92};

    int used_length = 5;

    printf("\nCurrent array is : ");
    display(array, used_length); // traversal operation

    int position, number;

    printf("\nEnter the position(0-%d) where you want to insert number --> ", used_length-1);
    scanf("%d", &position);

    printf("\nEnter the number(must be an integer) = ");
    scanf("%d", &number);

    int insertion_value = insert(array, &used_length, 100, position, number);

    printf("\nThe updated array is : ");
    display(array, used_length);

    (insertion_value == -1) ? (printf("\nInsertion failed !!")) : (printf("\nInsertion successful !! "));

    return 0;
}

void display(int *A, int used_size)
{
    for (int i = 0; i < used_size; i++)
    {
        printf("%d ", *(A+i));
    }
}

int insert(int *A, int *used_size, int array_capacity, int index, int new_number)
{
    if (*(used_size) == array_capacity)
    {
        return -1; // insertion not possible
    }
    else
    {
        // shifting the elements to right
        for (int i = *(used_size); i > index; i--)
        {
            *(A+i) = *(A+i-1);
        }

        *(A+index) = new_number; // inserting the new number in the desired index

        *(used_size) += 1; // updating the used size
        
        return 1;
    }
    

}