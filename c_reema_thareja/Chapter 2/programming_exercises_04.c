#include<stdio.h>

int main()
{
    int count = 0, sum = 0;
    for (int i = 1; i <= 200; i++)
    {
        if (i % 2 == 0)
        {
            count++;
            sum += i;
        }
        
    }

    printf("\nNumber of even numbers = %d", count);
    printf("\nSum of the even numbers = %d", sum);
    
    return 0;
}