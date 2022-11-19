#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int capacity;
    int front_index;
    int rear_index;
    int * array;
};

void print_queue(struct queue *);

void enqueue(struct queue *, int);

int isfull(struct queue *);

int dequeue(struct queue *);

int isempty(struct queue *);

int main()
{
    struct queue * pointer_to_queue = (struct queue *) malloc(sizeof(struct queue));

    pointer_to_queue->capacity = 15;
    pointer_to_queue->front_index = 14;
    pointer_to_queue->rear_index = 14;
    pointer_to_queue->array = (int *) malloc(pointer_to_queue->capacity * sizeof(int));

    *(pointer_to_queue->array) = 21;
    *(pointer_to_queue->array + 1) = 22;
    *(pointer_to_queue->array + 2) = 23;
    *(pointer_to_queue->array + 3) = 24;
    *(pointer_to_queue->array + 4) = 25;
    *(pointer_to_queue->array + 5) = 26;

    pointer_to_queue->rear_index = 5;

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

        printf("Do you want to exit ?? 0. NO 1. YES (0/1) -> ");
        scanf("%d", &exit_code);

        
    } while (!exit_code);
    
    return 0;
}

void print_queue(struct queue * A)
{
    printf("The queue is ::: ");

    int i = A->front_index;
    int j = A->rear_index;

    while (i != j)
    {
        i = (i + 1) % A->capacity;
        printf("%d ", *(A->array + i));

    }

    printf("\n");
}

void enqueue(struct queue * A, int number_to_be_enqueued)
{
    if (isfull(A))
    {
        printf("Queue overflow !!\n");
    }
    else
    {
        A->rear_index = ((A->rear_index + 1) % A->capacity);
        *(A->array + A->rear_index) = number_to_be_enqueued;
    }
}

int isfull(struct queue * A)
{
    if (((A->rear_index + 1) % A->capacity) == A->front_index)
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
        printf("Queue underflow !!\n");
        return -1; // assuming that the number -1 is not present in the queue
    }
    else
    {
        A->front_index = ((A->front_index + 1) % A->capacity);
        return *(A->array + A->front_index);
    }
}

int isempty(struct queue * A)
{
    if (A->front_index == A->rear_index)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}