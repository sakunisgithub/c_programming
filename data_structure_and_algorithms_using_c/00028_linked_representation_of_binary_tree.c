#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node * left;
    int data;
    struct node * right;
};

struct node * create_node(int number);

int main()
{
    struct node * node_1 = create_node(2); // the root node
    struct node * node_2 = create_node(1); 
    struct node * node_3 = create_node(4); 
    struct node * node_4 = create_node(11);
    struct node * node_5 = create_node(14);
    struct node * node_6 = NULL;
    struct node * node_7 = create_node(3);

    node_1->left = node_2;
    node_1->right = node_3;

    node_2->left = node_4;
    node_2->right = node_5;

    node_3->left = node_6;
    node_3->right = node_7;

    return 0;
}

struct node * create_node(int number)
{
    struct node * new_node = (struct node *) malloc(sizeof(struct node));

    new_node->left = NULL;
    new_node->data = number;
    new_node->right = NULL;

    return new_node;
}