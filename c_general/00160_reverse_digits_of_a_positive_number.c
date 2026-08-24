#include<stdio.h>
#include<math.h>

int main()
{
	int number;

	printf("Enter your positive integer = ");
	scanf("%d", &number);

	int original_number = number;

	int count = 0;

	if(number == 0){
		count = 1;
	}
	else{
		while(number != 0){
			number /= 10;
			count++;
		}
	}

	int reversed_number = 0;

	number = original_number;

	for(int i = count - 1; i >= 0; i--){
		reversed_number += (number % 10) * pow(10, i);
		number /= 10;
	}

	printf("Given number is %d and the reversed number is %d\n", original_number, reversed_number);

	return 0;
}
