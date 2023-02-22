#include<stdio.h>

int main()
{
	int row, column;
	
	printf("\n Enter the number of rows = ");
	scanf("%d", &row);
	
	printf("\n Enter the number of columns = ");
	scanf("%d", &column);
	
	int matrix[row][column];
	
	if(row != column)
	{
		printf("\n Number of rows is not equal to number of columns. So the matrix cannot be skew-symmetric");
	}
	else // when row == column
	{
		printf("\n Enter the matrix ::");
		
		int i, j;
		
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < row; j++)
			{
				printf("\n Enter matrix[%d][%d] = ", i+1, j+1);
				scanf("%d", &matrix[i][j]);
			}
		}
		
		
		int transposed_matrix[column][row];
		
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < row; j++)
			{
				transposed_matrix[i][j] = matrix[j][i];
			}
		}
		
		printf("\n The given matrix is :: \n");
		
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < row; j++)
			{
				printf("%d  ", matrix[i][j]);
			}
			printf("\n");
		}
		
		printf("\n The transposed matrix is :: \n");
		
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < row; j++)
			{
				printf("%d  ", transposed_matrix[i][j]);
			}
			printf("\n");
		}
		
		int code;
		
		for(i = 0; i < row; i++)
		{
			code = 1;
			
			for(j = 0; j < row; j++)
			{
				if( (matrix[i][j] + transposed_matrix[i][j]) != 0)
				{
					code = 0;
					break;
				}
			}
			
			if(code == 0)
			{
				break;
			}
		}
		
		if(code == 1)
		{
			printf("\n The matrix is skew-symmetric.");
		}
		else
		{
			printf("\n The matrix is not skew-symmetric.");
		}
	}	
	return 0;
}
