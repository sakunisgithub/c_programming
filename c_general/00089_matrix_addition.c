#include<stdio.h>

int main()
{
    int a, b, n;
    printf("\nEnter the number of matrices you want to sum = ");
    scanf("%d", &n);
    printf("\nEnter the common row length of the matrices = ");
    scanf("%d", &a);
    printf("\nEnter the common column length of the matrices = ");
    scanf("%d", &b);

    int matrix[n][a][b];

    // inputting the matrices
    for (int k = 0; k < n; k++)
    {
        printf("\nEnter matrix [%d] ::: ", k+1);
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                printf("\nEnter Matrix_[%d] : Element[%d][%d] = ",k+1, i+1, j+1);
                scanf("%d", &matrix[k][i][j]);
            }
        
        }
    }

    // calculating the sum
    int result[a][b];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                result[i][j] = result[i][j] + matrix[k][i][j];
                
            }
            
        }
        
    }
    

    // printing the recorded matrices
    for (int k = 0; k < n; k++)
    {
        printf("\nMatrix_[%d] is ::: \n", k+1);
        for (int i = 0; i < a; i++)
        {
           for (int j = 0; j < b; j++)
            {
               printf("%d\t",  matrix[k][i][j]);
            }
           printf("\n");       
        }
        printf("\n");       

    }
    

    // printing the sum
    printf("\nThe sum of the matrices is ::: \n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%d\t", result[i][j] );
        }
        printf("\n");
    }
    
    
    
    return 0;
}