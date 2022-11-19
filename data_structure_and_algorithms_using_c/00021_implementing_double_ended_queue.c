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

void enqueue_at_front(struct queue *, int);

int front_empty(struct queue *);

void enqueue_at_rear(struct queue *, int);

int rear_full(struct queue *);

int dequeue_at_front(struct queue *);

int isempty(struct queue *);

int dequeue_at_rear(struct queue *);

int rear_empty(struct queue *);

int main()
{
    struct queue * pointer_to_queue = (struct queue *) malloc(sizeof(struct queue));

    pointer_to_queue->capacity = 15;
    pointer_to_queue->front_index = -1;
    pointer_to_queue->rear_index = -1;
    pointer_to_queue->array = (int *) malloc(pointer_to_queue->capacity * sizeof(int));

    *(pointer_to_queue->array) = 1;
    *(pointer_to_queue->array + 1) = 2;
    *(pointer_to_queue->array + 2) = 3;

    pointer_to_queue->rear_index = 2;

    print_queue(pointer_to_queue);

    int option, number, exit_code;

    do
    {
        printf("What do you want to do? 1. ENQUEUE_AT_FRONT 2. ENQUEUE_AT_REAR 3. DEQUEUE_AT_FRONT 4. DEQUEUE_AT_REAR (1/2/3/4) -> ");
        scanf("%d", &option);

        if (option == 1)
        {
            printf("Enter the number you want to enqueue at front = ");
            scanf("%d", &number);
            enqueue_at_front(pointer_to_queue, number);
            
        }
        else if (option == 2)
        {
            printf("Enter the number you want to enqueue at rear = ");
            scanf("%d", &number);
            enqueue_at_rear(pointer_to_queue, number);
        }
        else if (option == 3)
        {
            int dequeued_number_1 = dequeue_at_front(pointer_to_queue);
            if (dequeued_number_1 != -1)
            {
                printf("The dequeued number is %d\n", dequeued_number_1);
            }
        }
        else if (option == 4)
        {
            int dequeued_number_2 = dequeue_at_rear(pointer_to_queue);
            if (dequeued_number_2 != -1)
            {
                printf("The dequeued number is %d\n", dequeued_number_2);
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
    printf("The queue is ::: ");

    for (int i = (A->front_index + 1); i <= A->rear_index; i++)
    {
        printf("%d ", *(A->array + i));
    }

    printf("\n");

}

void enqueue_at_front(struct queue * A, int number_to_be_enqueued)
{
    if (front_empty(A))
    {
        *(A->array + A->front_index) = number_to_be_enqueued;
        A->front_index--;
    }
    else
    {
        printf("Front is full !! Cannot enqueue element at front !!\n");
    }
    
}

int front_empty(struct queue * A)
{
    if (A->front_index == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}

void enqueue_at_rear(struct queue * A, int number_to_be_queued)
{
    if (rear_full(A))
    {
        printf("Rear is full !! Cannot enqueue element at rear !!\n");
    }
    else
    {
        A->rear_index++;
        *(A->array + A->rear_index) = number_to_be_queued;
    }
    
}

int rear_full(struct queue * A)
{
    if (A->rear_index == A->capacity - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int dequeue_at_front(struct queue * A)
{
    if (isempty(A))
    {
        printf("Front is empty !! Cannot dequeue from front !!\n");
        return -1; // assuming that the queue does not have -1 as an elememt
    }
    else
    {
        A->front_index++; 
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

int dequeue_at_rear(struct queue * A)
{
    if (rear_empty(A))
    {
        printf("Rear is empty !! Cannot dequeue element !!\n");
        return -1; // assumming that the number -1 is not present in the queue
    }
    else
    {
        int temp = *(A->array + A->rear_index);
        A->rear_index--;
        return temp;
    }
    
}

int rear_empty(struct queue * A)
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