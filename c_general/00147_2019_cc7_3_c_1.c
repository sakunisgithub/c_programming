#include<stdio.h>

int main()
{
    int numbers[15];

    printf("Enter the marks of the students :: \n");

    for (int i = 0; i < 15; i++)
    {
        printf("Enter number[%d] = ", i+1);
        scanf("%d", &numbers[i]);
    }
        
    int highest = numbers[0];

    for (int i = 1; i < 15; i++)
    {
        if (numbers[i] > highest)
        {
            highest = numbers[i]; 
        }
        
    }

    printf("The highest mark is %d\n", highest);

    printf("The roll number(s) with the highest mark is(are) :: \n");

    for (int i = 0; i < 15; i++)
    {
        if (numbers[i] == highest)
        {
            printf("%d\t", i+1); 
        }
        
    }
    
    
    return 0;
}