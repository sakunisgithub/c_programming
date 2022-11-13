#include<stdio.h>
// bubble sorting using functions
void display(int*,int);

void bubble_sort(int*, int);

void swap(int*, int*);

int main()
{
    int n;
    printf("Enter the length of your array = ");
    scanf("%d", &n);

    int array[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter array[%d] = ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\n");

    printf("The initial array is\n");
    display(array, n);

    bubble_sort(array, n);

    printf("\n");

    printf("The final array is\n");
    display(array, n);
    
    return 0;
}

void display(int* A, int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("%d  ", *(A+i));
    }
    
}

void bubble_sort(int* A, int a)
{
    // int sort_code = 0;
    for (int i = 0; i < a-1; i++)
    {
        printf("\nRunning pass number %d", i+1);
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