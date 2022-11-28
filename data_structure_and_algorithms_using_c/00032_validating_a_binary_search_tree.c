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

int is_binary_search_tree(struct node *);

int main()
{
    struct node * node_1 = create_node(9); // the root node
    struct node * node_2 = create_node(4);
    struct node * node_3 = create_node(11);
    struct node * node_4 = create_node(2);
    struct node * node_5 = create_node(7);
    struct node * node_6 = create_node(5);
    struct node * node_7 = create_node(8);
    struct node * node_8 = create_node(15);
    struct node * node_9 = create_node(14);

    node_1->left = node_2;
    node_1->right = node_3;

    node_2->left = node_4;
    node_2->right = node_5;

    node_5->left = node_6;
    node_5->right = node_7;

    node_3->right = node_8;

    node_8->left = node_9;

    printf("The binary tree is ::: ");
    inorder_traversal(node_1);

    if (is_binary_search_tree(node_1))
    {
        printf("\nThis is a binary search tree.");
    }
    else
    {
        printf("\nThis is not a binary search tree.");
    }
    
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

int is_binary_search_tree(struct node * root)
{
    static struct node * previous_node = NULL;

    if (root != NULL)
    {
        if (!is_binary_search_tree(root->left))
        {
            return 0;
        }
        else if (previous_node != NULL && root->data <= previous_node->data)
        {
            return 0;
        }

        previous_node = root;
        return (is_binary_search_tree(root->right));
    }
    else
    {
        return 1;
    }
}