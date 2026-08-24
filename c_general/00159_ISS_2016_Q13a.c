#include<stdio.h>

int main(){
	int number;
	printf("Enter your 5 digit number = ");
	scanf("%d", &number);

	int copy_number = number;

	int sum = 0;

	for(int i = 0; i < 5; i++){
		sum += number % 10;
		number /= 10;
	}

	printf("The sum of the digits of %d is %d\n", copy_number, sum);

	return 0;
}
