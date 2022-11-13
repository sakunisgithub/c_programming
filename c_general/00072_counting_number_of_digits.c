#include<stdio.h>

int main()
{
    unsigned long int number;
    // different data types support different range of values.
    // if you assign a variable to a particular data type, and then enter a value which is out of the range of that particular data type, you will get undesired output
    // to know all kinds of data types and their corresponding ranges, go to Programming in C, by Reema Thareja, Page no 21.
    printf("Enter your number with not more than 10 digits = "); //because unsigned long int supports values from 0 to 4294967295
    scanf("%lu", &number);
    // just out of curiosity or as a worthy experiment, input just 4294967295+1 i.e. 4294967296, and see you will get wrong output.
    // %lu is the format specifier for unsigned long integers
    int count = 0;

    if (number == 0)
    {
        printf("\nThe number of digits is 1.");
    }
    else
    {
        while (number != 0)
        {
            number = number/10; // In C programming, 5/2 is not equal to 2.5, 5/2 = 2 i.e. [2.5] in mathematics
            // In C programming, division between two integers returns an integer, the exact result if the dividend is completely divisible or the integer part of the quotient only if the dividend is not completely divisible
            count++;
        }

        printf("\nThe number of digits is %d", count);
    }

    return 0;
}