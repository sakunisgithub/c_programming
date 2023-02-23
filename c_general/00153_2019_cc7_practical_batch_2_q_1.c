#include<stdio.h>

int main()
{
	float lower[5], upper[5], frequency[5];
	
	printf("\n Enter the classes and respective frequencies :: ");
	
	int i;
	
	for(i = 0; i < 5; i++)
	{
		printf("\n Class[%d] :: Lower Boundary = ", i+1);
		scanf("%f", &lower[i]);
		
		printf("\n Class[%d] :: Upper Boundary = ", i+1);
		scanf("%f", &upper[i]);
		
		printf("\n Class[%d] :: Frequency = ", i+1);
		scanf("%f", &frequency[i]);
	}
	
	float max_frequency = frequency[0];
	int index = 0;
	
	for(i = 1; i < 5; i++)
	{
		if(frequency[i] > max_frequency)
		{
			max_frequency = frequency[i];
			index = i;
		}
	}
	
	float mode = lower[index] + ( (frequency[index] - frequency[index-1]) / (2*frequency[index] - frequency[index-1] - frequency[index+1]) ) * (upper[index] - lower[index]);
	
	printf("\n Mode of the data is %f", mode);
	
	return 0;
}