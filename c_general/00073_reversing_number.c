#include<stdio.h>

int main()
{
    int number;
    printf("\nEnter your number = ");
    scanf("%d", &number);

    int copy_number = number;

    int count = 0;
    if (copy_number == 0)
    {
        count = 1;
    }
    else
    {
        while (copy_number != 0)
        {
            copy_number = copy_number/10;
            count++;
        }
        
    }

    int digit[count];

    for (int i = 0; i < count; i++)
    {
        digit[i] = number - ((number/10)*10);
        number = number/10;
    }
    

    printf("\nThe reversed number is = ");
    for (int i = 0; i < count; i++)
    {
        printf("%d", digit[i]);
    }
    
    
    
    return 0;
}