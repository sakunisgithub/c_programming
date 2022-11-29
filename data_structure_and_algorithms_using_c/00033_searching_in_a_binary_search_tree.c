#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node * left;
    int data;
    struct node * right;
};

struct node * create_node(int);

struct node * search(struct node *, int);

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

    int find_number;
    printf("Enter the number you want to search = ");
    scanf("%d", &find_number);

    struct node * output = search(node_1, find_number);

    if (output == NULL)
    {
        printf("%d not found ! \n", find_number);
    }
    else
    {
        printf("%d found ! \n", find_number);
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

struct node * search(struct node * root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else if (key > root->data)
    {
        return search(root->right, key);
    }
}