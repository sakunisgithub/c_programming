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

void push(struct stack *, char);

char pop(struct stack *);

int match_characters(char, char);

int isempty(struct stack *);

int main()
{
    char expression[] = "[3-9(5-1){2-3}][50-(3*])";

    if (match_parenthesis(expression))
    {
        printf("All the parenthesis in the expression are balanced");
    }
    else
    {
        printf("All the parenthesis in the expression are not balanced");
    }
    
    return 0;
}

int match_parenthesis(char * exp)
{
    struct stack * pointer_to_stack = (struct stack *) malloc(sizeof(struct stack));

    pointer_to_stack->capacity = strlen(exp);
    pointer_to_stack->top = -1;
    pointer_to_stack->array = (char *) malloc(pointer_to_stack->capacity * sizeof(char));

    int i = 0;

    while (*(exp + i) != '\0')
    {
        if (*(exp + i) == '(' || *(exp + i) == '{' || *(exp + i) == '[')
        {
            push(pointer_to_stack, *(exp + i));
        }
        else if (*(exp + i) == ')' || *(exp + i) == '}' || *(exp + i) == ']')
        {
            char popped_character = pop(pointer_to_stack);

            if (!match_characters(popped_character, *(exp + i)))
            {
                return 0; // i.e. parenthesis don't match
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

void push(struct stack * A, char character_to_be_pushed)
{
    A->top++;
    *(A->array + A->top) = character_to_be_pushed;
    // we don't need to check whether the stack is full or not....because the size of the array in the stack is equal to that of the expression.....so no chance of overflow
}

char pop(struct stack * A)
{
    char temp = *(A->array + A->top);
    A->top--;
    return temp;
}

int match_characters(char A, char B)
{
    if (A == '(' && B == ')')
    {
        return 1;        
    }
    else if (A == '{' && B == '}')
    {
        return 1;        
    }
    else if (A == '[' && B == ']')
    {
        return 1;        
    }
    else
    {
        return 0;
    }
}

int isempty(struct stack * A)
{
    if (A->top != -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}