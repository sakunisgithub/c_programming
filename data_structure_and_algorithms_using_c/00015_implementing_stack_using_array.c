#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int capacity;
    int top;
    int * array;
};

void print_stack(struct stack *);

void push(struct stack *, int);

int isfull(struct stack *);

int pop(struct stack *);

int isempty(struct stack *);

int main()
{
    struct stack * pointer = (struct stack *) malloc(sizeof(struct stack));

    pointer->capacity = 10;
    pointer->top = -1;
    pointer->array = (int *) malloc(pointer->capacity * sizeof(int));

    *(pointer->array) = 11;
    *(pointer->array + 1) = 12;
    *(pointer->array + 2) = 13;
    *(pointer->array + 3) = 14;

    pointer->top = 3;

    print_stack(pointer);

    int option, exit_code;
    do
    {
        printf("What do you want to do ? 1. PUSH 2. POP (1/2) -> ");
        scanf("%d", &option);

        if (option == 1)
        {
            int number;
            printf("Enter the number you want to push = ");
            scanf("%d", &number);
            push(pointer, number);
            print_stack(pointer);
        }
        else if (option == 2)
        {
            int popped_number = pop(pointer);
            if (popped_number != -1)
            {
                printf("The popped number is %d\n", popped_number);
            }
            print_stack(pointer);
        }
        
        printf("Do you want to exit ? 0. NO 1. YES (0/1) -> ");
        scanf("%d", &exit_code);    
    

    } while (exit_code != 1);

    return 0;
}

void print_stack(struct stack * A)
{
    int element_counter = 0;

    printf("The stack is :: ");

    while (element_counter <= A->top)
    {
        printf("%d ", *(A->array + element_counter));
        element_counter++;
    }
    printf("\n");
}

void push(struct stack * A, int number_to_be_pushed)
{
    if (isfull(A))
    {
        printf("Stack Overflow !\n");
    }
    else
    {
        A->top++;
        *(A->array + A->top) = number_to_be_pushed;
    } 
}

int isfull(struct stack * A)
{
    if (A->top == A->capacity - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop(struct stack * A)
{
    if (isempty(A))
    {
        printf("Stack Underflow !\n");
        return -1; // assuming that the stack does not have -1 as an integer
    }
    else
    {
        int temp = *(A->array + A->top);
        A->top--;
        return temp;
    }
}

int isempty(struct stack * A)
{
    if (A->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}