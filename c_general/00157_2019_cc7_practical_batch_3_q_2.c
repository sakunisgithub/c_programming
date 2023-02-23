#include<stdio.h>

int main()
{
	int row, column;
	
	printf("\n Enter the number of rows = ");
	scanf("%d", &row);
	
	printf("\n Enter the number of columns = ");
	scanf("%d", &column);
	
	int matrix[row][column];
	
	printf("\n Enter the %d X %d matrix :: \n", row , column);
	
	int i, j;
	
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			printf("\n Enter matrix[%d][%d] = ", i+1, j+1);
			scanf("%d", &matrix[i][j]);
		}
	}
	
	int row_sums[row];
	
	for(i = 0; i < row; i++)
	{
		row_sums[i] = 0;
		
		for(j = 0; j < column; j++)
		{
			row_sums[i] += matrix[i][j];
		}
	}
	
	printf("\n The sum of the elements in the rows of the matrix are :: \n");
	
	for(i = 0; i < row; i++)
	{
		printf("\nRow[%d] --> %d\n", i+1, row_sums[i]);
	}
	
	return 0;
}