#include<stdio.h>


int main()
{
    int a, b;
    printf("\nEnter the number of rows = ");
    scanf("%d", &a);
    printf("\nEnter the number of columns = ");
    scanf("%d", &b);

    int array[a][b];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("\nEnter array[%d][%d] = ", i+1, j+1);
            scanf("%d", &array[i][j]);
        }
        
    }

    printf("\nThe initial matrix is :: \n");
    // printing the recorded array using their index
    
    /* for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    } */


    // printing the recorded array using pointers
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%d\t", *(*(array+i)+j) );
        }
        printf("\n");
    }

    int transpose_array[b][a];

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            transpose_array[j][i] = array[i][j];
        }
        
    }
    printf("The transpose matrix is ::: \n");
    
    // printing the transposed array using the index of the elements
    
    /* for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
        {
            printf("%d\t", transpose_array[i][j]);
        }
        printf("\n");
    } */
    

    // printing the transposed array using pointers
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
        {
            printf("%d\t", *(*(transpose_array+i)+j) );
        }
        printf("\n");
    }
    
    
    
    return 0;
}