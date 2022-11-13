#include<stdio.h>
/* 
The steps are as follows::
1. taking the values as inputs from the user and creating another copy array on which we shall do all the operations
2. bubble sorting the array is descending order
3. evaluating the dense rank of the sorted elements  ::: we are initialising the rank of the greatest value
by assigning its rank as 1. now we are creating a for loop. If two successive elements are equal, we are assinging the rank of the previous value to the latter one. 
If two successive elements are not equal, we are increamenting the previous rank by adding 1 and assigning to the current value.
4. Now we have the sorted array and their ranks. but that's not what we exactly wanted. We wanted to display initial values
and their corresponding ranks in a tabular form.
            So, we create another array where we opt to store the corresponding ranks of the initial array. 
Then we take each element of the sorted array, find it in the initial array. Once found, we assign corresponding rank to the
final array. Understand the indexes properly.
5. Finally we print the initial values and their corresponding dense ranks.
*/

void bubble_sort(int*, int);

void swap(int*, int*);

int main()
{
    // STEP 1
    int n;
    printf("\nEnter the number of values = ");
    scanf("%d", &n);

    int value[n], value_copy[n];
    printf("\nEnter the values::\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter value[%d] = ", i+1);
        scanf("%d", &value[i]);
        value_copy[i] = value[i];
    }

    // STEP 2
    bubble_sort(value_copy, n); // now we have the elements of the array in descending order

    // STEP 3 ::: evaluating the dense ranks
    int dense_rank[n];
    
    dense_rank[0] = 1;

    for (int i = 1; i < n; i++)
    {
        if ( *(value_copy+i) == *(value_copy+i-1) )
        {
            dense_rank[i] = dense_rank[i-1];
        }
        else if ( *(value_copy+i) != *(value_copy+i-1))
        {
            dense_rank[i] = dense_rank[i-1] + 1;
        }
    }

    // STEP 4
    int final_dense_rank[n];

    for (int i = 0; i < n; i++) // accessing the elements of the sorted array
    {
        for (int j = 0; j < n; j++) // accessing the elements of the initial array
        {
            if (value_copy[i] == value[j])
            {
                final_dense_rank[j] = dense_rank[i];
            }
            
        }
        
    }
    
    // STEP 5 ::: printing the values, with their corresponding dense rank
    
    printf("\nThe recorded values, the sorted values along with their corresponding dense rank are as follows :: \n");
    printf("\n\t Initial Values \t Dense Ranks\n");
    printf("\n------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%5d \t \t \t \t%5d\n",value[i], final_dense_rank[i]);
    }
    
    return 0;
}

void bubble_sort(int* A, int a)
{
    for (int i = 0; i < a-1; i++)
    {
        int code = 0;
        for (int j = 0; j < a-1-i; j++)
        {
            if (*(A+j) < *(A+j+1)) // we are directily putting < here in order to sort the array in descending order
            {
                swap( (A+j), (A+j+1));
                code = 1;
            }
            
        }
        if (code == 0)
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