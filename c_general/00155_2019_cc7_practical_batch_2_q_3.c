#include<stdio.h>
#include<math.h>

int factorial(int);

int main()
{
	float m;
	
	printf("\n Enter the parameter of Poisson Distribution (m) = ");
	scanf("%f", &m);
	
	int k;
	
	printf("\n Enter the value of k = ");
	scanf("%d", &k);
	
	float sum = 0;
	
	int i;
	
	for(i = 0; i <= k; i++)
	{
		sum += exp(-(m)) * ( (pow(m, i)) / (factorial(i)) );
	}
	
	printf("P(X <= %d) = %f", k, sum);
	
	return 0;
}

int factorial(int n)
{
	if(n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return (n * factorial(n-1));
	}
}