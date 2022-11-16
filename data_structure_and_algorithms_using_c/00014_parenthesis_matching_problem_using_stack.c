#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int match_parenthesis(char *);

struct stack
{
    int capacity;
    int top;
    char * array;
};

void push(struct stack *);

int isfull(struct stack *);

int pop(struct stack *);

int isempty(struct stack *);

int main()
{
    char expression[13] = "8)*(9)";

    if (match_parenthesis(expression))
    {
        printf("The parenthesis in the expression is balanced\n");
    }
    else
    {
        printf("The parenthesis in the expression is not balanced\n");
    }
    

    return 0;
}

int match_parenthesis(char * array_of_expression)
{
    struct stack * pointer_to_stack = (struct stack *) malloc(sizeof(struct stack));

    pointer_to_stack->capacity = strlen(array_of_expression);
    pointer_to_stack->top = -1;
    pointer_to_stack->array = (char *) malloc(pointer_to_stack->capacity * sizeof(char));

    int i = 0;
    while (* (array_of_expression + i ) != '\0')
    {
        if (* (array_of_expression + i) == '(')
        {
            push(pointer_to_stack);
        }
        else if (* (array_of_expression + i ) == ')')
        {
            int num = pop(pointer_to_stack);
            if (num == 0)
            {
                return 0; 
            }
            
        }

        i++;
    }

    if (isempty(pointer_to_stack))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void push(struct stack * A)
{
    if (isfull(A))
    {
        printf("Stack Overflow !\n");
    }
    else
    {
        A->top++;
        *(A->array + A->top) = '(';
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
        return 0; // i.e. when pop unsuccessful this happens when there is no ( in stack but we are trying to pop a )
    }
    else
    {
        A->top--;
        return 1; // i.e. when pop is successful
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