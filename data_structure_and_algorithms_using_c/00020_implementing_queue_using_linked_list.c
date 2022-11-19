#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * pointer;
};

struct queue
{
    struct node * front_pointer;
    struct node * rear_pointer;
};

void print_queue(struct queue *);

void enqueue(struct queue *, int);

int isfull(struct queue *);

int dequeue(struct queue *);

int isempty(struct queue *);

int main()
{
    struct node * head_node = (struct node *) malloc(sizeof(struct node));
    struct node * second_node = (struct node *) malloc(sizeof(struct node));
    struct node * third_node = (struct node *) malloc(sizeof(struct node));
    struct node * fourth_node = (struct node *) malloc(sizeof(struct node));
    struct node * fifth_node = (struct node *) malloc(sizeof(struct node));

    head_node->data = 11;
    head_node->pointer = second_node;

    second_node->data = 12;
    second_node->pointer = third_node;

    third_node->data = 13;
    third_node->pointer = fourth_node;

    fourth_node->data = 14;
    fourth_node->pointer = fifth_node;

    fifth_node->data = 15;
    fifth_node->pointer = NULL;

    struct queue * pointer_to_queue = (struct queue *) malloc(sizeof(struct queue));

    pointer_to_queue->front_pointer = head_node;
    pointer_to_queue->rear_pointer = fifth_node;

    print_queue(pointer_to_queue);
    
    int option, number, exit_code;

    do
    {
        printf("What do you want to do? 1. ENQUEUE 2. DEQUEUE (1/2) -> ");
        scanf("%d", &option);

        if (option == 1)
        {
            printf("Enter the number you want to enqueue = ");
            scanf("%d", &number);
            enqueue(pointer_to_queue, number);
        }
        else if (option == 2)
        {
            int dequeued_number = dequeue(pointer_to_queue);
            if (dequeued_number != -1)
            {
                printf("The dequeued number is %d\n", dequeued_number);
            }
        }

        print_queue(pointer_to_queue);

        printf("Do you want to exit? 0. NO 1. YES (0/1) -> ");
        scanf("%d", &exit_code);
    
        
    } while (!exit_code);
    
    return 0;
}

void print_queue(struct queue * A)
{
    struct node * temp = A->front_pointer;

    printf("The queue is ::: ");

    while (temp != NULL)
    {
        printf("%d ", (temp->data));
        temp = temp->pointer;
    }

    printf("\n");
    
}

void enqueue(struct queue * A, int number_to_be_enqueued)
{
    if (isfull(A))
    {
        printf("Queue overflow !! \n");
    }
    else
    {
        struct node * new_node = (struct node *) malloc(sizeof(struct node));

        new_node->data = number_to_be_enqueued;
        new_node->pointer = NULL;
        if (A->front_pointer == NULL)
        {
            A->front_pointer = new_node;
            A->rear_pointer = new_node; 
        }
        else
        {
            A->rear_pointer->pointer = new_node;
            A->rear_pointer = new_node;
        }
        
    }
}

int isfull(struct queue * A)
{
    struct node * request_new_node = (struct node *) malloc(sizeof(struct node));

    if (request_new_node == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int dequeue(struct queue * A)
{
    if (isempty(A))
    {
        printf("Queue underflow !! \n");
        return -1; // assumming that -1 is not present in the queue
    }
    else
    {
        int temp = A->front_pointer->data;
        struct node * temp_node = A->front_pointer;
        A->front_pointer = A->front_pointer->pointer;
        free(temp_node);
        return temp;
    }
}

int isempty(struct queue * A)
{
    if (A->front_pointer == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}