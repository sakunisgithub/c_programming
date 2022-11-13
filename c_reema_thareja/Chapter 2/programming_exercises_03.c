#include<stdio.h>

int main()
{
    // reading 10 integers
    int integers[10];
    for (int i = 0; i < 10; i++)
    {
        printf("\nEnter integer[%d] = ", i+1);
        scanf("%d", &integers[i]);
    }

    // printing the integers as asked
    for (int i = 0; i < 10; i++)
    {
        printf("%d,", integers[i]);
        if ((i % 3) == 2)
        {
            printf("\n");
        }
        
    }
    
    
    return 0;
}