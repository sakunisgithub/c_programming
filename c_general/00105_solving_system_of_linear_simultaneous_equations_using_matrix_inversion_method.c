#include<stdio.h>

int main()
{
    int row;
    printf("\nEnter the number of equations = ");
    scanf("%d", &row);

    float matrix[row][row];
    float constant[row], result[row];

    // inputting the coefficient matrix
    printf("\nEnter the coefficients of the variables ::: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("\nEnter matrix[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    // inputting the constant matrix

    printf("\nEnter the constants ::: \n");
    for (int i = 0; i < row; i++)
    {
        printf("\nEnter constant[%d] = ", i+1);
        scanf("%f", &constant[i]);
    }

    // creating the required identity matrix

    float identity[row][row]; // the operand matrix

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (i == j)
            {
                identity[i][j] = 1;
            }
            else
            {
                identity[i][j] = 0;
            }
        }
    }

    // inversing the coefficient matrix [refer to "104_inverse_of_a_matrix.c" to understand inversing of a matrix]

    for (int c = 0; c < row; c++) 
    {
        for (int r = 0; r < row; r++) 
        {
            if (r != c) 
            {
                float ratio = matrix[r][c] / matrix[c][c];
                for (int i = 0; i < row; i++)
                {
                    matrix[r][i] = matrix[r][i] - (ratio * matrix[c][i]); 

                    identity[r][i] = identity[r][i] - (ratio * identity[c][i]); 
                }
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        if (matrix[i][i] != 1)
        {
            for (int j = 0; j < row; j++)
            {
                identity[i][j] = identity[i][j] / matrix[i][i]; 
            }
            for (int j = 0; j < row; j++)
            {
                matrix[i][j] = matrix[i][j] / matrix[i][i]; 
            }
        }
    }

    // printing the inverse of the coefficient matrix
    printf("\nThe inverse matrix is ::: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%f\t", identity[i][j]);
        }
        printf("\n");
    }

    // multiplying the inverted matrix with the constant matrix

    for (int i = 0; i < row; i++)
    {
        result[i] = 0;
        for (int j = 0; j < row; j++)
        {
            float product = identity[i][j] * constant[j];
            result[i] = result[i] + product;
        }
        
    }

    // printing the result matrix
    printf("\nThe result matrix is ::: \n");
    for (int i = 0; i < row; i++)
    {
        printf("\n%f", result[i]);
    }

return 0;
}