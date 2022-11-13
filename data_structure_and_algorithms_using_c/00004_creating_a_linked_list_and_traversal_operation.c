#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *pointer;
};

void display_linked_list(struct node *);

int main()
{
    struct node *base_node;
    struct node *second_node;
    struct node *third_node;

    base_node = (struct  node *) malloc(sizeof(struct node *));
    second_node = (struct  node *) malloc(sizeof(struct node *));
    third_node = (struct  node *) malloc(sizeof(struct node *));

    base_node->data = 10;
    base_node->pointer = second_node;

    second_node->data = 20;
    second_node->pointer = third_node;

    third_node->data = 30;
    third_node->pointer = NULL;

    // printing the data of the linked list / traversal operation
    display_linked_list(base_node);

    return 0;
}

void display_linked_list(struct node *POINTER)
{
    while (POINTER != NULL)
    {
        printf("Data : %d\n", POINTER->data);
        POINTER = POINTER->pointer;
    }
}