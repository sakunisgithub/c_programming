#include<stdio.h>

int main()
{
    int n;
    printf("\nEnter the order of the matrix = ");
    scanf("%d", &n);

    float matrix[n][n];
    float determinant = 1;

    // taking input from the user
    printf("\nEnter the matrix = ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\nEnter matrix[%d][%d] = ", i+1, j+1);
            scanf("%f", &matrix[i][j]);
        }
        
    }

    // printing the recorded matrix using pointers
    printf("\nThe matrix is ::: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%f\t", ( *(*(matrix+i) + j ) ) );
        }
        printf("\n");
    }

    

    for (int k = 0; k < n; k++)
    {
        for (int i = k+1; i <= n; i++)
        {
            if (matrix[k][k] != 0)
            {
                float ratio = matrix[i][k] / matrix[k][k];
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = matrix[i][j] - ratio*matrix[k][j];
                }
            }
        }
    }
    printf("\nThe transformed matrix is ::: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%f\t", ( *(*(matrix+i) + j ) ) );
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        determinant = determinant * matrix[i][i];
    }
    printf("\nThe determinant is %f", determinant);
    
    
    return 0;
}