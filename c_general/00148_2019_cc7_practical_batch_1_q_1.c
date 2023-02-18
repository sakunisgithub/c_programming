#include<stdio.h>

void sort_numbers(int *, int);

void swap(int *, int *);

float mean(int *, int, int, int);

int main()
{
	int n;
	
	printf("Enter the number of values = ");
	scanf("%d", &n);
	
	int numbers[n];
	
	int i;
	for(i = 0; i < n; i++)
	{
		printf("Enter number[%d] = ", i+1);
		scanf("%d", &numbers[i]);
	}
	
	printf("\nThe initial numbers are :: ");
	
	for(i = 0; i < n; i++)
	{
		printf("%d  ", numbers[i]);
	}
	
	sort_numbers(numbers, n);
	
	printf("\nThe sorted(in ascending order) numbers are :: ");
	
	for(i = 0; i < n; i++)
	{
		printf("%d  ", numbers[i]);
	}
	
	int k = ((n * 10)/100);
	
	int new_length = n - (2*k);
	
	float desired_mean = mean(numbers, new_length, k, n-k);
	
	printf("\nThe mean of the remaining numbers is %f", desired_mean);
	
	return 0;
	
}

void sort_numbers(int * A, int length)
{
	int i, j;
	for(i = 0; i < length-1; i++)
	{
		for(j = i+1; j < length; j++)
		{
			if(*(A+i) > *(A+j))
			{
				swap((A+i), (A+j));
			}
		}
	}
}

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

float mean(int * A, int length, int start, int stop)
{
	int i, sum = 0;
	
	for(i = start; i <= stop; i++)
	{
		sum += *(A+i);
	}
	
	return ((float)sum / (float)length);
}
