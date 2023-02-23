#include<stdio.h>

int main()
{
	int x_values[7] = {100, 150, 200, 250, 300, 350, 400};
	
	float y_values[7] = {10.63, 13.03, 15.04, 16.81, 18.42, 19.90, 21.27};
	
	float numerator[7], denominator[7];
	
	int i;
	
	for(i = 0; i < 7; i++)
	{
		numerator[i] = 1, denominator[i] = 1;
		
		int j;
		
		for(j = 0; j < 7; j++)
		{
			if(i != j)
			{
				numerator[i] *= (218 - x_values[j]);
				
				denominator[i] *= (x_values[i] - x_values[j]);
			}
		}
	}
	
	float sum = 0;
	
	for(i = 0; i < 7; i++)
	{
		sum += ( (numerator[i] / denominator[i]) * y_values[i]);
	}
	
	printf("\n The required value of Y is %f", sum);
	
	return 0;
}