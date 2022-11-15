#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * pointer; // this is the pointer to the next element in the linked list
};

struct node * top = NULL;

struct node * push(struct node *, int);

int isFull();

void print_linked_list(struct node *);

int pop(struct node **);

int isEmpty(struct node *);

int main()
{
	printf("The initial linked list is empty\n");

	int number, code;
	printf("Enter the number you want to push = ");
	scanf("%d", &number);	

	top = push(top, number);
	if (top == NULL) 
	{
		printf("push unsuccessful !\n");
	}

	print_linked_list(top);

	do 
	{
		int option;
		printf("What do you want to do? 1. PUSH 2. POP (1/2) ->" );
		scanf("%d", &option);

		if (option == 1) 
		{
			printf("Enter the number you want to push = ");
			scanf("%d", &number);	
			top = push(top, number);
			if (top == NULL) 
			{
				printf("push unsuccessful !\n");
			}
		} 
		else 
		{
			int popped_number;
			popped_number = pop(&top);
			if (popped_number != 0) 
			{
				printf("pop successful !\n");
				printf("The popped number is = %d\n", popped_number);
			}
			else 
			{
				printf("pop unsuccessful !\n");
			}
		}

		print_linked_list(top);
	
		printf("Do you want to exit ? 0. NO 1. YES (0/1) -> ");
		scanf("%d", &code);

	} while (!code);

	return 0;
}

struct node * push(struct node * A, int number_to_be_pushed)
{
	if (isFull()) 
	{
		printf("Stack Overflow.\n");
		return NULL;
	}
	else 
	{
		struct node * new_top = (struct node*) malloc(sizeof(struct node));
		new_top->data = number_to_be_pushed;
		new_top->pointer = A;
		return new_top;
	}
}

int isFull()
{
	struct node * ptr = (struct node*) malloc(sizeof(struct node));
	if (ptr == NULL) 
	{
		return 1;
	} 
	else 
	{
		return 0;
	}
}

void print_linked_list(struct node * A)
{
	int element_counter = 0;
	while (A != NULL) 
	{
		printf("Element[%d] = %d\n", element_counter, A->data);
		A = A->pointer;
		element_counter++;
	}
}

int pop(struct node ** A)
{
	if (isEmpty(*A)) 
	{
		printf("Stack Underflow\n");
		return 0; // assuming that the number 0 is not present in the stack
	} 
	else 
	{
		struct node * temp_ptr = *A;
		int temp = (*A)->data;
		(*A) = (*A)->pointer;
		free(temp_ptr);
		return temp;
	}
}

int isEmpty(struct node * A)
{
	if (A == NULL) 
	{
		return 1;
	} 
	else 
	{
		return 0;
	}	
}
