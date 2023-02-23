#include<stdio.h>

int main()
{
	int n;
	
	printf("\n Enter the number of values = ");
	scanf("%d", &n);
	
	int values[n];
	
	printf("\n Enter the values :: \n");
	
	int i;
	
	for(i = 0; i < n; i++)
	{
		printf("\n Enter value[%d] = ", i+1);
		scanf("%d", &values[i]);
	}
	
	int minimum, maximum;
	
	// finding the minimum value
	
	minimum = values[0];
	
	for(i = 1; i < n; i++)
	{
		if(values[i] < minimum)
		{
			minimum = values[i];
		}
	}
	
	// finding the maximum value
	
	maximum = values[0];
	
	for(i = 1; i < n; i++)
	{
		if(values[i] > maximum)
		{
			maximum = values[i];
		}
	}
	
	int l = (minimum / 10) * 10;
	
	int u = ((maximum / 10) + 1) * 10;
	
	int number_of_classes = (u - l) / 10; // as class length is given 10
	
	int lower[number_of_classes], upper[number_of_classes], frequency[number_of_classes];
	
	// creating the class boundaries
	
	for(i = 0; i < number_of_classes; i++)
	{
		lower[i] = l + (i * 10);
		
		upper[i] = lower[i] + 10;
	}
	
	// calculating the frequencies of the classes
	
	for(i = 0; i < number_of_classes; i++)
	{
		frequency[i] = 0;
		
		int j;
		
		for(j = 0; j < n; j++)
		{
			if(values[j] >= lower[i] && values[j] < upper[i])
			{
				frequency[i]++;
			}
		}
	}
	
	FILE *pointer = NULL;
	
	pointer = fopen("output_file_3.txt", "w");
	
	fprintf(pointer, "\t Class Intervals \t Frequencies \n");
	
	for(i = 0; i < number_of_classes; i++)
	{
		fprintf(pointer, "\t  %3d - %3d  \t\t\t   %2d   \n", lower[i], upper[i], frequency[i]);
	}
	
	return 0;
}