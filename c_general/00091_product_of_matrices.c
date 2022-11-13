#include<stdio.h>

int main()
{
    int a, b, c, d;
    printf("\nEnter the row length of the first matrix = ");
    scanf("%d", &a);
    printf("\nEnter the column length of the first matrix = ");
    scanf("%d", &b);
    printf("\nEnter the row length of the second matrix = ");
    scanf("%d", &c);
    printf("\nEnter the column length of the second matrix = ");
    scanf("%d", &d);

    int matrix_1[a][b];
    int matrix_2[c][d];

    if (b == c)
    {
        printf("\nEnter the first matrix :: \n");
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                printf("\nEnter Matrix_1 [%d][%d] = ", i+1, j+1);
                scanf("%d", &matrix_1[i][j]);
            }
        
        }

        printf("\nEnter the second matrix :: \n");
        for (int i = 0; i < c; i++)
        {
            for (int j = 0; j < d; j++)
            {
                printf("\nEnter Matrix_2 [%d][%d] = ", i+1, j+1);
                scanf("%d", &matrix_2[i][j]);
            }
        
        }
    
        int result[a][d];
    
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < d; j++)
            {
                result[i][j] = 0;
                for (int k = 0; k < b; k++)
                {
                    int product = matrix_1[i][k] * matrix_2[k][j];
                    result[i][j] = result[i][j] + product;
                }
            
            }
        
        }
    

        printf("\nThe resultant matrix i.e. (matrix_1 X matrix_2) is ::: \n");

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < d; j++)
            {
                printf("%d\t", *(*(result+i)+j) );
            }
            printf("\n");
        }

    
    }

    else
    {
        printf("\nOoopss!!! Matrix multiplication is not possible.");
    }
    
    
    return 0;
}