#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node * left;
    int data;
    struct node * right;
};

struct node * create_node(int);

void inorder_traversal(struct node *);

int main()
{
    struct node * node_1 = create_node(4); // the root node
    struct node * node_2 = create_node(1);
    struct node * node_3 = create_node(6);
    struct node * node_4 = create_node(5);
    struct node * node_5 = create_node(2);

    node_1->left = node_2;
    node_1->right = node_3;

    node_2->left = node_4;
    node_2->right = node_5;

    printf("The binary tree is ::: ");
    inorder_traversal(node_1);

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

void inorder_traversal(struct node * root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}