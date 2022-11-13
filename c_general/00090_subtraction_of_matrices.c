#include<stdio.h>

int main()
{
    int a, b;
    printf("\nEnter the common row length of the matrices = ");
    scanf("%d", &a);
    printf("\nEnter the common column length of the matrices = ");
    scanf("%d", &b);

    int matrix_1[a][b];
    int matrix_2[a][b];

    printf("\nEnter the first matrix ::: ");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("\nEnter Matrix_1 [%d][%d] = ", i+1, j+1);
            scanf("%d", &matrix_1[i][j]);
        }
        
    }

    printf("\nEnter the second matrix ::: ");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("\nEnter Matrix_2 [%d][%d] = ", i+1, j+1);
            scanf("%d", &matrix_2[i][j]);
        }
        
    }

    int result[a][b];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            result[i][j] = matrix_1[i][j] - matrix_2[i][j];
        }
        
    }
    
    printf("\nThe first matrix is ::: \n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%d\t", *(*(matrix_1+i)+j) );
        }
        printf("\n");       
    }
    
    printf("\nThe second matrix is ::: \n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%d\t", *(*(matrix_2+i)+j) );
        }
        printf("\n");       
    }
    

    printf("\nThe subtraction of the second matrix from the first matrix is ::: \n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%d\t", *(*(result+i)+j) );
        }
        printf("\n");
    }
    return 0;
}