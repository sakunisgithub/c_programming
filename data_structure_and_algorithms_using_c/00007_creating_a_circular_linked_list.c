#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * pointer;
};

void print_circular_linked_list(struct node *);

struct node * insert_at_first(struct node *, int);

int main()
{
    struct node * base_node = (struct node *) malloc(sizeof(struct node));
    struct node * second_node = (struct node *) malloc(sizeof(struct node));
    struct node * third_node = (struct node *) malloc(sizeof(struct node));
    struct node * fourth_node = (struct node *) malloc(sizeof(struct node));

    base_node->data = 10;
    base_node->pointer = second_node;

    second_node->data = 11;
    second_node->pointer = third_node;

    third_node->data = 12;
    third_node->pointer = fourth_node;

    fourth_node->data = 13;
    fourth_node->pointer = base_node;

    printf("The initial circular linked list is ::\n");
    print_circular_linked_list(base_node);

    int value;
    printf("Enter the value you want to insert = ");
    scanf("%d", &value);
    base_node = insert_at_first(base_node, value);
    printf("Insertion successful !! \nThe updated circular linked list is ::\n");
    print_circular_linked_list(base_node);

    return 0;
}

void print_circular_linked_list(struct node * A)
{
    struct node * head_node = A;

    int element_counter = 0;
    do
    {
        printf("Element %d :: %d\n", element_counter, A->data);
        A = A->pointer;
        element_counter++;
    } while (A != head_node);
}

struct node * insert_at_first(struct node * A, int data_to_be_inserted)
{
    /* 
    1. request memory for the new node
    2. the last node currently has the address of the incumbent base node. we traverse to the last node and store the address of the newly created node (which will be the new head node)
    3. in the newly created node, we store the address of the incumbent base node and the value we want to insert
    4. return the newly created node which is now the base node
    */
    struct node * new_base_node = (struct node *) malloc(sizeof(struct node));

    struct node * current_base_node = A;
    while (A->pointer != current_base_node)
    {
        A = A->pointer;
    }
    A->pointer = new_base_node;
    
    new_base_node->data = data_to_be_inserted;
    new_base_node->pointer = current_base_node;
    
    return new_base_node;
}