#include<stdio.h>

void check(int);

int count = 0;

int main()
{
    int lower, upper;
    printf("\nEnter your lower limit = ");
    scanf("%d", &lower);

    printf("\nEnter your upper limit = ");
    scanf("%d", &upper);
    
    printf("\nThe prime number(s) is/are : ");
    
    for (int i = lower; i <= upper; i++)
    {
        check(i);
    }
    if (count == 0)
    {
        printf("\nOops!!!!There is no prime number present.");
    }
    
    
    return 0;
}

void check(int a)
{
    int n;
    for (int i = 2; i < a; i++)
    {
        n = a%i;
        if (n == 0)
        {
            break;
        }
    }


    if (n != 0 && a != 1)
    {
        printf("%d\t", a);
        count++;
    }
    
    
}