#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int number_of_chances[6] = {1, 2, 3, 4, 5, 6};
	
	int number_of_candidates[6] = {145, 68, 46, 21, 11, 4};
	
	int weighted_sum = 0, total_frequency = 0;
	
	int i;
	
	for(i = 0; i < 6; i++)
	{
		weighted_sum += number_of_chances[i] * number_of_candidates[i];
		
		total_frequency += number_of_candidates[i];
	}
	
	float weighted_mean = (float)weighted_sum / (float)total_frequency;
	
	float p = 1/weighted_mean;
	
	int N = total_frequency;
	
	printf("\n The mean of the given data is %f", weighted_mean);
	
	
	FILE *pointer = NULL;
	
	pointer = fopen("output_file_1.txt", "w");
	
	fprintf(pointer, "\tK\t\tNumber of Candidates\t\tNp(1-p)^(K-1)\n");
	
	float alpha[6];
	
	for(i = 0; i < 6; i++)
	{
		alpha[i] = N * p * (pow((1-p), i));
	}
	
	for(i = 0; i < 6; i++)
	{
		fprintf(pointer, "\n\t%d\t\t\t%d\t\t\t\t\t\t%f\n", i+1, number_of_candidates[i], alpha[i]);
	}
	
	fclose(pointer);
	
	return 0;
}