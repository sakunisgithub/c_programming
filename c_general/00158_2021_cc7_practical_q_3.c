#include<stdio.h>

int main()
{
	int A[3][3] = {1, 5, 1, -1, -7, -1, 0, 2, 1};
	
	int identity[3][3] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	
	int A_square[3][3];
	
	int i, j;
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			A_square[i][j] = 0;
			
			int k;
			
			for(k = 0; k < 3; k++)
			{
				A_square[i][j] += (A[i][k] * A[k][j]);
			}
		}
	}
	
	int final_matrix[3][3];
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			final_matrix[i][j] = A_square[i][j] - (2 * A[i][j]) + identity[i][j];
		}
	}
	
	printf("\n The original matrix is :: \n");
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%3d  ", A[i][j]);
		}
		
		printf("\n");
		
	}
	
	printf("\n The resultant matrix is :: \n");
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%3d  ", final_matrix[i][j]);
		}
		
		printf("\n");
		
	}
	
	return 0;
}