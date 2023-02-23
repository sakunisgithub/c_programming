#include<stdio.h>

int matrix[4][3];

void display_matrix(FILE*);

void swap(int);

int main()
{
	FILE *pointer = NULL;

	pointer = fopen("output_file_2.txt", "w");
	
	printf("\n Enter the 4X3 matrix :: \n");
	
	int i, j;
	
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("\n Enter matrix[%d][%d] = ", i+1, j+1);
			scanf("%d", &matrix[i][j]);
		}
	}
	
	fprintf(pointer, "\n The initial matrix was :: \n");
	display_matrix(pointer);
	
	for(i = 0; i < 3; i++)
	{
		swap(i);
	}
	
	fprintf(pointer, "\n The new matrix is :: \n");
	display_matrix(pointer);
	
	
	fclose(pointer);
	
	return 0;
}

void display_matrix(FILE *ptr)
{
	int i, j;
	
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 3; j++)
		{
			fprintf(ptr, "%3d  ", matrix[i][j]);
		}
		
		fprintf(ptr, "\n");
	}
}

void swap(int index)
{
	int temp = matrix[1][index];
	matrix[1][index] = matrix[2][index];
	matrix[2][index] = temp;
}