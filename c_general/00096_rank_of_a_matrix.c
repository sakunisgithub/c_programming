#include<stdio.h>

int main()
{
    // input
    int row, col;
    printf("\nEnter the number of rows of the matrix :: ");
    scanf("%d", &row);
    printf("\nEnter the number of columns of the matrix :: ");
    scanf("%d", &col);

    float matrix[row][col];

    printf("\nEnter the matrix :: ");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("\nEnter matrix[%d][%d] = ", i+1, j+1);
            scanf("%f", &matrix[i][j]);
        }

    }

    // displaying the recorded matrix

    printf("\nThe initial matrix is ::: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }

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
    // printf("\nalpha = %d\n", alpha);
    int count_bar = 0, code;

    for (int c = 0; c < alpha; c++)
    {
        if (matrix[c-count_bar][c] != 0)
        {
            // printf("\nc = %d\n", c);
            // printf("\ncount_bar = %d\n", count_bar);
            float pivot = matrix[c-count_bar][c];
            // printf("%f\n", pivot);
            for (int i = 0; i < col; i++)
            {
                matrix[c-count_bar][i] = matrix[c-count_bar][i] / pivot;
            }

            pivot = matrix[c-count_bar][c];
            // printf("%f\n", pivot);

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
                /* printf("\n\n");
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        printf("%f\t", matrix[i][j]);
                    }
                    printf("\n");
                } */
            }
        }
        
        else if (matrix[c-count_bar][c] == 0)
        {
            if (c-count_bar == row-1)
            {
                // printf("\n1");
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
                        // printf("\nwhile swapping c = %d\n", c);
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
                    --c; // c is decremented only when one row is swapped with the current matrix[c] row. now we must have matrix[c][c] as non-zero. so we want to run the code with the same c value once again.
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
    // printf("\n%d", zero_row);
    

    // printing the row reduced echelon form of the initial matrix
    printf("\nThe row reduced echelon form of the initial matrix is ::: \n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nThe rank of the matrix is %d", row - zero_row);
    
    return 0;
}