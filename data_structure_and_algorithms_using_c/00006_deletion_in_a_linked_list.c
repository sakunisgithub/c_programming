#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * pointer;
};

void print_linked_list(struct node *);

struct node * delete_the_head_node(struct node *);

void delete_the_last_node(struct node *);

void delete_node_in_between(struct node *, int);

struct node * delete_a_given_value(struct node *, int);

int main()
{
	struct node * base_node = (struct node *) malloc(sizeof(struct node));
	struct node * second_node = (struct node *) malloc(sizeof(struct node));  	
	struct node * third_node = (struct node *) malloc(sizeof(struct node));
	struct node * fourth_node = (struct node *) malloc(sizeof(struct node));
	struct node * fifth_node = (struct node *) malloc(sizeof(struct node));
	struct node * sixth_node = (struct node *) malloc(sizeof(struct node));

	base_node->data = 15;
	base_node->pointer = second_node;
	
	second_node->data = 16;
	second_node->pointer = third_node;

	third_node->data = 17;
	third_node->pointer = fourth_node;
	
	fourth_node->data = 18;
	fourth_node->pointer = fifth_node;

	fifth_node->data = 19;
	fifth_node->pointer = sixth_node;

	sixth_node->data = 20;
	sixth_node->pointer = NULL;

	printf("The initial linked list is ::\n");
	print_linked_list(base_node);

	printf("The options are :: \n");
	printf("1. Deletion at the first\n");
	printf("2. Deletion in between\n");
	printf("3. Deletion at the end\n");
	printf("4. Deletion of a value\n");

	int option, index, value;
	printf("Choose your option = ");
	scanf("%d", &option);

	if (option == 1)
	{
		printf("Deleting the head node .... \n");
		base_node = delete_the_head_node(base_node);
		printf("Deletion of the head node successful !! \nThe updated linked list is :: \n");
		print_linked_list(base_node);
	}
	else if (option == 2)
	{
		printf("Enter the index of the element you want to delete = ");
		scanf("%d", &index);
		delete_node_in_between(base_node, index);
		printf("Deletion of the element successful !! \nThe updated linked list is :: \n");
		print_linked_list(base_node);
	}
	else if (option == 3)
	{
		printf("Deleting the last node .... \n");
		delete_the_last_node(base_node);
		printf("Deletion of the last node successful !! \nThe updated linked list is :: \n");
		print_linked_list(base_node);
	}
	else if (option == 4)
	{
		printf("Enter the value you want to delete = ");
		scanf("%d", &value);
		struct node * returned_pointer = delete_a_given_value(base_node, value);
		if (returned_pointer == NULL)
		{
			printf("Element not found in linked list !! \nDeletion not successful !!");
		}
		else
		{
			printf("Deletion successful !! \nThe updated linked list is ::\n");
			base_node = returned_pointer;
			print_linked_list(base_node);
		}
	}
	else
	{
		printf("Invalid option input !!");
	}

	return 0;
}

void print_linked_list(struct node * A)
{
	int element_counter = 0;
	
	while ( A != NULL )
	{
		printf("Element %d :: %d\n", element_counter, A->data);
		A = A->pointer;
		element_counter++;
	}
}

struct node * delete_the_head_node(struct node * A)
{
	struct node * temp = A->pointer;
	free(A);
	return temp;
}

void delete_the_last_node(struct node * A)
{
	struct node * next_node_to_A = A->pointer;

	while (next_node_to_A->pointer != NULL)
	{
		A = A->pointer;
		next_node_to_A = A->pointer;
	}
	
	free(next_node_to_A);
	A->pointer = NULL;
}

void delete_node_in_between(struct node * A, int index)
{
	int element_counter = 0;

	while (element_counter != index - 1)
	{
		A = A->pointer;
		element_counter++;
	}

	struct node * node_to_be_deleted = A->pointer;

	A->pointer = node_to_be_deleted->pointer;

	free(node_to_be_deleted);
}

struct node * delete_a_given_value(struct node * A, int value)
{
	struct node * base_node = A;

	if (A->data == value) // i.e. we are asked to delete the first node or head node
	{
		struct node * new_head_pointer = delete_the_head_node(A);
		return new_head_pointer;
	}
	
	struct node * next_node_to_A = A->pointer;
	while (next_node_to_A->data != value && next_node_to_A->pointer != NULL)
	{
		A = A->pointer;
		next_node_to_A = A->pointer;
	}

	if (next_node_to_A->data != value && next_node_to_A->pointer == NULL) // i.e. value not found upto the last node
	{
		return NULL;
	}
	
	if (next_node_to_A->data == value)
	{
		A->pointer = next_node_to_A->pointer;
		free(next_node_to_A);
		return base_node;
	}
}