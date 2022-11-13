#include<stdio.h>

int main()
{
    int a;
    printf("\nEnter the number of rows of the square matrix :: ");
    scanf("%d", &a);

    int array[a][a];

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            printf("\nEnter array[%d][%d] = ", i+1, j+1);
            scanf("%d", &array[i][j]);
        }
        
    }
    
    int sum = 0;
    for (int i = 0; i < a; i++)
    {
        sum = sum + array[i][i];
    }
    
    printf("\nThe matrix is ::: \n");

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            printf("%d\t", *(*(array+i)+j) );
        }
        printf("\n");
    }
    
    printf("\nThe trace of the matrix is %d", sum);
    
    return 0;
}