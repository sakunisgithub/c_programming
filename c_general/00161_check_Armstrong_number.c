#include<stdio.h>
#include<math.h>

int main()
{
	int number;

	printf("Enter your number = ");
	scanf("%d", &number);

	int original_number = number;

	int sum_of_cubes = 0;

	if(number != 0){
		while(number != 0){
			sum_of_cubes += pow(number % 10, 3);
			number /= 10;
		}
	}

	number = original_number;

	if(number == sum_of_cubes){
		printf("%d is an Armstrong number\n", original_number);
	}
	else{
		printf("%d is not an Armstrong number\n", original_number);
	}

	return 0;
}
