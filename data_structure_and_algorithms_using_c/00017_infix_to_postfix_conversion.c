#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// the operators considered are +,-,*,/ only

char * infix_to_postfix(char *);

struct stack
{
    int capacity;
    int top;
    char * array;
};

int isoperator(char);

int precedence(char);

char stacktop(struct stack *);

void push(struct stack *, char);

char pop(struct stack *);

int isempty(struct stack *);

int main()
{
    char infix_expression[] = "x-y/z-k*d";

    printf("Your postfix expression is %s", infix_to_postfix(infix_expression));
    return 0;
}

char * infix_to_postfix(char * infix)
{
    struct stack * pointer_to_stack = (struct stack *) malloc(sizeof(struct stack));

    pointer_to_stack->capacity = strlen(infix);
    pointer_to_stack->top = -1;
    pointer_to_stack->array = (char *) malloc(pointer_to_stack->capacity * sizeof(char));

    char * postfix_expression = (char *) malloc( (strlen(infix)+1) * sizeof(char) );

    int i = 0, j = 0;

    while (*(infix + i) != '\0')
    {
        if (!isoperator(*(infix + i)))
        {
            *(postfix_expression + j) = *(infix + i);
            i++;
            j++;
        }
        else 
        {
            if (precedence(*(infix + i)) > precedence(stacktop(pointer_to_stack)))
            {
                push(pointer_to_stack, *(infix + i));
                i++;
            }
            else
            {
                *(postfix_expression + j) = pop(pointer_to_stack);
                j++;
            }
        }
    }

    while (!isempty(pointer_to_stack))
    {
        *(postfix_expression + j) = pop(pointer_to_stack);
        j++;
    }

    *(postfix_expression + j) = '\0';

    return postfix_expression;
}

int isoperator(char character)
{
    if (character == '+' || character == '-' || character == '*' || character == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char character)
{
    if (character == '+' || character == '-')
    {
        return 1;
    }
    else if (character == '*' || character == '/')
    {
        return 2;   
    }
    else
    {
        return 0;
    }
}

char stacktop(struct stack * A)
{
    return *(A->array + A->top);
}

char pop(struct stack * A)
{
    char temp = *(A->array + A->top);
    A->top--;
    return temp;
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

void push(struct stack * A, char operator_to_be_pushed)
{
    A->top++;
    *(A->array + A->top) = operator_to_be_pushed;
    // no need to check the instance of stack overflow
}