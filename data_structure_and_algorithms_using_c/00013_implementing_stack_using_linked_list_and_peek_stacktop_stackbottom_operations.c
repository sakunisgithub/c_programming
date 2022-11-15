#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * pointer;
};

int peek(struct node *, int);

int stacktop(struct node *);

int stackbottom(struct node *);

int main()
{
	struct node * head_node = (struct node*) malloc(sizeof(struct node));
	struct node * second_node = (struct node*) malloc(sizeof(struct node));
	struct node * third_node = (struct node*) malloc(sizeof(struct node));
	struct node * fourth_node = (struct node*) malloc(sizeof(struct node));

	head_node->data = 10;
	head_node->pointer = second_node;

	second_node->data = 11;
	second_node->pointer = third_node;

	third_node->data = 12;
	third_node->pointer = fourth_node;

	fourth_node->data = 13;
	fourth_node->pointer = NULL;
	
	struct node * top = head_node;

	int index;
	printf("Enter the position you want to peek = ");
	scanf("%d", &index);

	int number = peek(top, index);
	if (number != -1) 
	{
		printf("The integer at position %d is %d \n", index, number);
	}
	
	printf("Stacktop = %d\n", stacktop(top));

	printf("Stackbottom = %d\n", stackbottom(top));

	return 0;
}

int peek(struct node * A, int index_to_peek)
{
	int element_counter = 0;
	while (element_counter != index_to_peek - 1 && A != NULL) 
	{
		A = A->pointer;
		element_counter++;
	}
	if (A != NULL) 
	{
		return A->data;
	} 
	else 
	{
		printf("Invalid Position input !!\n");
		return -1; // assumming that the linked list does not have -1 as an element
	}
}

int stacktop(struct node * A)
{
	return A->data;
}

int stackbottom(struct node * A)
{
	while (A->pointer != NULL) 
	{
		A = A->pointer;
	}
	return A->data;
}
