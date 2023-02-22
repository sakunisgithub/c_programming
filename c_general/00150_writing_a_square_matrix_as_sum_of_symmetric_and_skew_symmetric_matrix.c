#include<stdio.h>

int main()
{
	int order;
	
	printf("\n Enter the order of the square matrix = ");
	scanf("%d", &order);
	
	int matrix[order][order];
	
	printf("\n Enter the matrix :: \n");
	
	int i, j;
	
	for(i = 0; i < order; i++)
	{
		for(j = 0; j < order; j++)
		{
			printf("\n Enter matrix[%d][%d] = ", i+1, j+1);
			scanf("%d", &matrix[i][j]);
		}
	}
	
	int transposed_matrix[order][order];
	
	for(i = 0; i < order; i++)
	{
		for(j = 0; j < order; j++)
		{
			transposed_matrix[i][j] = matrix[j][i];
		}
	}
	
	float symmetric_matrix[order][order];
	float skew_symmetric_matrix[order][order];
	
	for(i = 0; i < order; i++)
	{
		for(j = 0; j < order; j++)
		{
			symmetric_matrix[i][j] = (float)(matrix[i][j] + transposed_matrix[i][j])/(float)2;
		}
	}
	
	for(i = 0; i < order; i++)
	{
		for(j = 0; j < order; j++)
		{
			skew_symmetric_matrix[i][j] = (float)(matrix[i][j] - transposed_matrix[i][j])/(float)2;
		}
	}
	
	
	printf("\n The required symmetric matrix is :: \n");
	
	for(i = 0; i < order; i++)
	{
		for(j = 0; j < order; j++) 
		{
			printf("%f  ", symmetric_matrix[i][j]);
		}
		printf("\n");
	}
	
	printf("\n The required skew symmetric matrix is :: \n");
	
	for(i = 0; i < order; i++)
	{
		for(j = 0; j < order; j++) 
		{
			printf("%f  ", skew_symmetric_matrix[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
