#include<stdio.h>

/* 
Accept roll numbers and corresponding marks in Math of n students in two different arrays. 
Sort the students based according to their marks. 
*/

void bubble_sort(int*, int, int*);

void swap(int*, int*);

int main()
{
    int n;
    printf("\nEnter the number of students = ");
    scanf("%d", &n);

    int roll[n], marks[n];

    // input the roll numbers and the marks

    printf("\nEnter the roll numbers and corresponding marks of the students ::: \n");

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter roll[%d] --> ", i+1);
        scanf("%d", &roll[i]);
        printf("\nEnter marks[%d] --> ", i+1);
        scanf("%d", &marks[i]);
    }

    // sorting the marks in descending order

    bubble_sort(marks, n, roll);

    // printing the output
    printf("\n\t Roll Number \t \t \t Marks\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n\t %5d \t \t \t \t %5d\n", roll[i], marks[i]);
    }
    
    return 0;
}

void bubble_sort(int* A, int a, int* B)
{
    for (int i = 0; i < a-1; i++)
    {
        int sort_code = 0;

        for (int j = 0; j < a-1-i; j++)
        {
            if ( *(A+j) < *(A+j+1) )
            {
                swap( (A+j), (A+j+1));
                swap( (B+j), (B+j+1));
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