#include<stdio.h>

float matrix[20][20];

int rank(int, int);

int main()
{
    int ROW, var;
    printf("\nEnter the number of variables = ");
    scanf("%d", &var);
    printf("\nEnter the number of equations = ");
    scanf("%d", &ROW);

    float coefficient_matrix[ROW][var], constant[ROW], augmented[ROW][var+1];

    // inputting the coefficient matrix
    printf("\nInput the coefficient matrix :: \n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < var; j++)
        {
            printf("\nEnter coefficient matrix[%d][%d] = ", i+1, j+1);
            scanf("%f", &coefficient_matrix[i][j]);
        }
        
    }

    // inputting the constant matrix
    printf("\nInput the constants :: \n");
    for (int i = 0; i < ROW; i++)
    {
        printf("\nEnter constant[%d] = ", i+1);
        scanf("%f", &constant[i]);
    }
    

    // creating the augmented matrix
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < var+1; j++)
        {
            if (j == var)
            {
                augmented[i][j] = constant[i];
            }
            else
            {
                augmented[i][j] = coefficient_matrix[i][j];
            }
            
        }
        
    }

    // printing the recorded coefficient matrix
    printf("\nThe coefficient matrix is :: \n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < var; j++)
        {
            printf("%f\t", coefficient_matrix[i][j]);
        }
        printf("\n");
    }
    
    
    // printing the recorded constant matrix
    printf("\nThe constant matrix is :: \n");
    for (int i = 0; i < ROW; i++)
    {
        printf("%f\n", constant[i]);
    }
    
    
    // printing the recorded coefficient matrix
    printf("\nThe augmented matrix is :: \n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < var+1; j++)
        {
            printf("%f\t", augmented[i][j]);
        }
        printf("\n");
    }


    // finding rank of the coefficient matrix
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < var; j++)
        {
            matrix[i][j] = coefficient_matrix[i][j];
        }
        
    }
    
    int rank_coefficient = rank(ROW, var);
    printf("\nThe rank of the coefficient matrix is %d\n", rank_coefficient);

    
    // finding the rank of the augmented matrix
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < var+1; j++)
        {
            matrix[i][j] = augmented[i][j];
        }
        
    }

    int rank_augmented = rank(ROW, var+1);
    printf("\nThe rank of the augmented matrix is %d\n", rank_augmented);

    if (rank_coefficient != rank_augmented)
    {
        printf("\nThe system of linear equations is inconsistent and has no solution.\n");
    }
    if ( (rank_augmented == rank_coefficient) && (rank_augmented == var) )
    {
        printf("\nThe system of linear equations is consistent and has unique solution.\n");
    }
    if ( (rank_augmented == rank_coefficient) && (rank_coefficient < var) )
    {
        printf("\nThe system of linear equations is consistent and has infinite solutions.\n");
    }
    
    
    


    
    return 0;
}

int rank(int row, int col)
{
    int alpha;

    if (row < col)
    {
        alpha = row;
    }
    if (row > col)
    {
        alpha = col;
    }
    if (row == col)
    {
        alpha = row;
    }

    int count_bar = 0, code;

    for (int c = 0; c < alpha; c++)
    {
        if (matrix[c-count_bar][c] != 0)
        {
            float pivot = matrix[c-count_bar][c];

            for (int i = 0; i < col; i++)
            {
                matrix[c-count_bar][i] = matrix[c-count_bar][i] / pivot;
            }

            pivot = matrix[c-count_bar][c];

            for (int r = 0; r < row; r++)
            {
                if (r != c-count_bar)
                {
                    float ratio = matrix[r][c];

                    for (int i = 0; i < col; i++)
                    {
                        matrix[r][i] = matrix[r][i] - ratio * matrix[c-count_bar][i];
                    }

                }
            }
        }
        
        else if (matrix[c-count_bar][c] == 0)
        {
            if (c-count_bar == row-1)
            {
                break;
            }
            else
            {
                int r;
                for (r = c-count_bar+1; r < row; r++)
                {
                    if (matrix[r][c] != 0)
                    {
                        for (int i = 0; i < col; i++)
                        {
                            float temp;
                            temp = matrix[r][i];
                            matrix[r][i] = matrix[c-count_bar][i];
                            matrix[c-count_bar][i] = temp;
                        }
                        code = 1; // i.e. when one row is swapped successfully
                        break;
                    }
                }

                if (r == row)
                {
                    count_bar++;
                    if (alpha + 1 <= col)
                    {
                        alpha++;
                    }
                        
                }
                    

                if (code == 1)
                {
                    --c; 
                    code = 0;                    
                }
                
            }
            
        }
        
    }

    int zero_row = 0; // counting the number of zero rows
    for (int r = 0; r < row; r++)
    {
        int count1 = 0;
        for (int i = 0; i < col; i++)
        {
            if (matrix[r][i] == 0)
            {
                count1++;
            }
            
        }
        if (count1 == col)
        {
            zero_row++;
        }
        
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            matrix[i][j] == 0;
        }
        
    }
    

    return row-zero_row;
}