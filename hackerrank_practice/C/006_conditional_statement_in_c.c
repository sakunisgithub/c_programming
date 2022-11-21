#include<stdio.h>
#include<stdlib.h>


int main()
{
    unsigned long int integer;
    scanf("%lu", &integer);

    if (integer >= 1 && integer <= 9)
    {
        if (integer == 1)
        {
            printf("one\n");
        }
        else if (integer == 2)
        {
            printf("two\n");
        }
        else if (integer == 3)
        {
            printf("three\n");
        }
        else if (integer == 4)
        {
            printf("four\n");
        }
        else if (integer == 5)
        {
            printf("five\n");
        }
        else if (integer == 6)
        {
            printf("six\n");
        }
        else if (integer == 7)
        {
            printf("seven\n");
        }
        else if (integer == 8)
        {
            printf("eight\n");
        }
        else
        {
            printf("nine\n");
        }
    }
    else if (integer > 9)
    {
        printf("Greater than 9\n");
    }
    
    return 0;
}