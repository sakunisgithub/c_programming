#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int capacity;
    int front_index;
    int back_index;
    int * array;
};

void print_queue(struct queue *);

void enqueue(struct queue *, int);

int dequeue(struct queue *);

int isempty(struct queue *);

int isfull(struct queue *);

int main()
{
    struct queue * pointer_to_queue = (struct queue *) malloc(sizeof(struct queue));

    pointer_to_queue->capacity = 15;
    pointer_to_queue->front_index = -1;
    pointer_to_queue->back_index = -1;
    pointer_to_queue->array = (int *) malloc(pointer_to_queue->capacity * sizeof(int));

    printf("The initial queue is empty !\n");

    int option, exit_code, number, dequeued_number;
    do
    {
        printf("What do you want to do?? 1. ENQUEUE 2. DEQUEUE (1/2) -> ");
        scanf("%d", &option);

        if (option == 1)
        {
            printf("Enter the number you want to enqueue = ");
            scanf("%d", &number);
            enqueue(pointer_to_queue, number);
            print_queue(pointer_to_queue);

        }
        else if (option == 2)
        {
            dequeued_number = dequeue(pointer_to_queue);
            if (dequeued_number != -1)
            {
                printf("The dequeued number is %d\n", dequeued_number);
                print_queue(pointer_to_queue);
            }
        }

        printf("Do you want to exit ? 0. NO 1. YES (0/1) -> ");
        scanf("%d", &exit_code);
       

    } while (!exit_code);
    
    return 0;
}

void print_queue(struct queue * A)
{
    printf("The queue is :: ");
    for (int i = A->front_index + 1; i <= A->back_index; i++)
    {
        printf("%d ", *(A->array + i));
    }
    printf("\n");
}

void enqueue(struct queue * A, int integer_to_be_enqueued)
{
    if (isfull(A))
    {
        printf("Queue overflow !\n");
    }
    else
    {
        A->back_index++;
        *(A->array + A->back_index) = integer_to_be_enqueued;
    }
}

int dequeue(struct queue * A)
{
    if (isempty(A))
    {
        printf("Queue Underflow !\n");
        return -1; // assuming that the queue does not have -1 as an element
    }
    else
    {
        A->front_index++;
        return *(A->array + A->front_index);
    }
}

int isempty(struct queue * A)
{
    if (A->front_index == A->back_index)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(struct queue * A)
{
    if (A->back_index == A->capacity - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}