#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * pointer;
};

void print_linked_list(struct node *);

struct node * insert_at_first(struct node *, int);

void insert_in_between(struct node *, int, int);

void insert_at_end(struct node *, int);

int main()
{
    struct node * base_node;
    struct node * second_node;
    struct node * third_node;
    struct node * fourth_node;

    base_node = (struct node *) malloc(sizeof(struct node));
    second_node = (struct node *) malloc(sizeof(struct node));
    third_node = (struct node *) malloc(sizeof(struct node));
    fourth_node = (struct node *) malloc(sizeof(struct node));

    base_node->data = 10;
    base_node->pointer = second_node;

    second_node->data = 11;
    second_node->pointer = third_node;

    third_node->data = 12;
    third_node->pointer = fourth_node;

    fourth_node->data = 13;
    fourth_node->pointer = NULL;

    printf("The initial linked list is ::\n");
    print_linked_list(base_node);

    printf("Option 1 : Add one integer at the first\n");
    printf("Option 2 : Insert one integer at index (1-3)\n");
    printf("Option 3 : Append one integer at the end\n");

    int option;
    printf("Choose your option (1/2/3) ---> ");
    scanf("%d", &option);

    if (option == 1)
    {
        // insertion at first
        int new_data_for_insertion_at_first;
        printf("Enter the number you want to insert at first = ");
        scanf("%d", &new_data_for_insertion_at_first);

        base_node = insert_at_first(base_node, new_data_for_insertion_at_first);

        printf("Insertion at first successful !\nThe updated linked list is ::\n");
        print_linked_list(base_node);
    }
    else if (option == 2)
    {
        // insertion in between
        int index, new_data_for_insertion_in_between;
        printf("Enter the index at which you want to insert = ");
        scanf("%d", &index);
        printf("Enter the number you want to enter = ");
        scanf("%d", &new_data_for_insertion_in_between);

        insert_in_between(base_node, index, new_data_for_insertion_in_between);
        printf("Insertion in between successful !\nThe updated linked list is ::\n");
        print_linked_list(base_node);
    }
    else if (option == 3)
    {
        // insertion at end
        int new_data_for_insertion_at_the_end;

        printf("Enter the number you want to insert at the end = ");
        scanf("%d", &new_data_for_insertion_at_the_end);

        insert_at_end(base_node, new_data_for_insertion_at_the_end);
        printf("Insertion at end successful ! \nThe updated linked list is ::\n");
        print_linked_list(base_node);
    }

    return 0;
}

void print_linked_list(struct node * A)
{
    int element_counter = 0;
    while (A != NULL)
    {
        printf("Element %d :: %d\n", element_counter, A->data);
        A = A->pointer;
        element_counter++;
    }
    
}

struct node * insert_at_first(struct node * A, int number_to_be_inserted)
{
    struct node * new_base_node = (struct node *) malloc(sizeof(struct node));

    new_base_node->data = number_to_be_inserted;
    new_base_node->pointer = A;

    return new_base_node;
}

void insert_in_between(struct node * A, int index, int number_to_be_inserted)
{
    int element_index = 0;

    while (element_index != index - 1)
    {
        A = A->pointer;
        element_index++;
    }

    struct node * new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = number_to_be_inserted;
    new_node->pointer = A->pointer;

    A->pointer = new_node;
    
}

void insert_at_end(struct node * A, int number_to_be_inserted)
{
    while (A->pointer != NULL)
    {
        A = A->pointer;
    }

    struct node * new_node = (struct node *) malloc(sizeof(struct node));
    A->pointer = new_node;

    new_node->data = number_to_be_inserted;
    new_node->pointer = NULL;
    
}