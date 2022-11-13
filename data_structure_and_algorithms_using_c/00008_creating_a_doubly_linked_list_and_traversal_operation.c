#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node * pointer_of_previous_node;
	int data;
	struct node * pointer_of_next_node;
};

void print_doubly_linked_list(struct node *);

int main()
{
	struct node * base_node = (struct node *) malloc(sizeof(struct node));
	struct node * second_node = (struct node *) malloc(sizeof(struct node));
	struct node * third_node = (struct node *) malloc(sizeof(struct node));
	struct node * fourth_node = (struct node *) malloc(sizeof(struct node));
	struct node * fifth_node = (struct node *) malloc(sizeof(struct node));
	struct node * sixth_node = (struct node *) malloc(sizeof(struct node));
	struct node * seventh_node = (struct node *) malloc(sizeof(struct node));
	struct node * eighth_node = (struct node *) malloc(sizeof(struct node));
	struct node * ninth_node = (struct node *) malloc(sizeof(struct node));
	struct node * tenth_node = (struct node *) malloc(sizeof(struct node));

	base_node->pointer_of_previous_node = NULL;
	base_node->data = 10;
	base_node->pointer_of_next_node = second_node;

	second_node->pointer_of_previous_node = base_node;
	second_node->data = 11;
	second_node->pointer_of_next_node = third_node;

	third_node->pointer_of_previous_node = second_node;
	third_node->data = 12;
	third_node->pointer_of_next_node = fourth_node;

	fourth_node->pointer_of_previous_node = third_node;
	fourth_node->data = 13;
	fourth_node->pointer_of_next_node = fifth_node;

	fifth_node->pointer_of_previous_node = fourth_node;
	fifth_node->data = 14;
	fifth_node->pointer_of_next_node = sixth_node;

	sixth_node->pointer_of_previous_node = fifth_node;
	sixth_node->data = 15;
	sixth_node->pointer_of_next_node = seventh_node;

	seventh_node->pointer_of_previous_node = sixth_node;
	seventh_node->data = 16;
	seventh_node->pointer_of_next_node = eighth_node;

	eighth_node->pointer_of_previous_node = seventh_node;
	eighth_node->data = 17;
	eighth_node->pointer_of_next_node = ninth_node;

	ninth_node->pointer_of_previous_node = eighth_node;
	ninth_node->data = 18;
	ninth_node->pointer_of_next_node = tenth_node;

	tenth_node->pointer_of_previous_node = ninth_node;
	tenth_node->data = 19;
	tenth_node->pointer_of_next_node = NULL;
	
	printf("Traversing and printing the doubly linked list ....\n\n");
	print_doubly_linked_list(base_node);
 	
	free(base_node);
	free(second_node);
	free(third_node);
	free(fourth_node);
	free(fifth_node);
	free(sixth_node);
	free(seventh_node);
	free(eighth_node);
	free(ninth_node);
	free(tenth_node);

	return 0;
}

void print_doubly_linked_list(struct node * A)
{
	int element_counter = 0;
	
	struct node * last_node;

	printf("Traversing the linked list in conventional way .....\n");
	while (A != NULL)
	{
		printf("Element %d :: %d\n", element_counter, A->data); 
		
		if (A->pointer_of_next_node == NULL)
		{
			last_node = A;
		}

		A = A->pointer_of_next_node;
		element_counter++;
	}
	
	element_counter--;
	
	printf("Traversing the linked list in reverse way ....\n");
	while (last_node != NULL)
	{
		printf("Element %d :: %d\n", element_counter, last_node->data);
		last_node = last_node->pointer_of_previous_node;
		element_counter--;
	} 
}
