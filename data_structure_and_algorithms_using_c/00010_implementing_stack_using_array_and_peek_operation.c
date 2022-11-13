#include<stdio.h>
#include<stdlib.h>

struct stack 
{
	int capacity;
	int top;
	int * array;
};

int peek(struct stack *, int);

int main()
{
	struct stack * pointer = (struct stack *) malloc(sizeof(struct stack));
	pointer->capacity = 10;
	pointer->top = -1;
	pointer->array = (int *) malloc(pointer->capacity * sizeof(int));

	*(pointer->array) = 11;
	*(pointer->array + 1) = 12;
	*(pointer->array + 2) = 13;
	*(pointer->array + 3) = 14;
	*(pointer->array + 4) = 15;

	pointer->top = 4;

	printf("The capacity of the array is %d\n", pointer->capacity);
	int position;
	printf("Enter the position you want to peek = ");
	scanf("%d", &position);

	int number = peek(pointer, position);
	if (number != -1)
	{
	 printf("The number is %d\n", number);
	}
	return 0;
}

int peek(struct stack * A, int position_to_peek)
{
	if (A->top - position_to_peek + 1 < 0)
	{
		printf("Invalid position !!!\n");
		return -1; // assuming that the number -1 will not be present in the stack
	}
	else
	{
		return *(A->array + A->top - position_to_peek+1);
	}
}
