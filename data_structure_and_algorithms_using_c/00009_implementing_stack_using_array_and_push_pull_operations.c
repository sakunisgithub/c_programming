#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int capacity;
	int top;
	int * array;
};

int check_status(struct stack *);

void push(struct stack *, int);

int pop(struct stack *);
int main()
{
	struct stack * pointer = (struct stack *) malloc(sizeof(struct stack));

	pointer->capacity = 20;
	pointer->top = -1;
	pointer->array = (int *) malloc(pointer->capacity * sizeof(int));
	
	printf("The stack capacity is %d\n", pointer->capacity);

	*(pointer->array) = 5;
	*(pointer->array + 1) = 6;
	*(pointer->array + 2) = 7;
	pointer->top = 2;

	int exit_code;

	do
	{
		int option, number, popped_number;
		int result = check_status(pointer);
		
		if(result == -1)
		{
			printf("The operation you can perform is ::: PUSH\n");
			printf("Do you want to push??? 1. YES 0. NO (0/1) -> ");
			scanf("%d", &option);
			if(option == 1)
			{
				printf("Enter the number you want to push = ");
				scanf("%d", &number);
				push(pointer, number);
			}
		}
		else if(result > -1 && result < pointer->capacity - 1)
		{
			printf("The operations you can perform are ::: 1. PUSH 2. POP\n");
			printf("Choose your option -> ");
			scanf("%d", &option);
			if(option == 1)
			{
				printf("Enter the number you want to push = ");
				scanf("%d", &number);
				push(pointer, number);
			}
			else if(option == 2)
			{
				popped_number = pop(pointer);	
				printf("The popped number is %d\n", popped_number);

			}
		}
		else if(result == pointer->capacity)
		{
			printf("The operation you can perform is ::: 1. POP\n");
			printf("1. POP 0.Don't POP\n");
			scanf("%d", &option);
			if(option == 1)
			{
				popped_number = pop(pointer);
				printf("The popped number is %d\n", popped_number);
			}
		}
		
		check_status(pointer);
		
		printf("Do you want to exit?? 1. EXIT 0. Don't EXIT (1/0) -> ");
		scanf("%d", &exit_code);

	}while(exit_code != 1);

	return 0;
}

int check_status(struct stack * A)
{
	if (A->top == -1) // i.e. the stack is completely empty
	{
		printf("The stack is completely empty.\n");
		return -1;
	}
	else if (A->top > -1 && A->top < A->capacity - 1) // i.e. the stack is neither completely empty nor completely full
	{
		printf("The stack is :: ");
		for (int i = 0; i <= A->top; i++)
		{
			printf("%d ", *(A->array + i));
		}
		printf("\n");
		return A->top;
	}
	else if (A->top == A->capacity - 1) // i.e. the stack is completely full
	{
		printf("The stack is completely full.\n");
		printf("The stack is :: ");
		for (int i = 0; i <= A->top; i++)
		{
			printf("%d ", *(A->array + i));
		}
		printf("\n");
		return A->capacity;
	}
}

void push(struct stack * A, int number_to_be_pushed)
{
	A->top++;
	*( A->array + A->top ) = number_to_be_pushed;
}

int pop(struct stack * A)
{
	int temp = *(A->array + A->top);
	A->top--;
	return temp;
}
