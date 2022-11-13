#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int capacity;
	int top;
	int * array;
};

int stacktop(struct stack *);

int stackbottom(struct stack *);

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
	*(pointer->array + 5) = 16;

	pointer->top = 5;
	
	printf("The bottom element of the stack is %d\n", stackbottom(pointer));
	printf("The top element of the stack is %d\n", stacktop(pointer));

	return 0;
}

int stacktop(struct stack * A)
{
	return *(A->array + A->top);
}

int stackbottom(struct stack * A)
{
	return *(A->array);
}
