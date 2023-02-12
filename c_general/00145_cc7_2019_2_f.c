#include<stdio.h>

int main()
{
    int number_of_inputs;

    printf("Enter the number of real numbers you want to input = ");
    scanf("%d", &number_of_inputs);
   
    int count = 0;

    for (int i = 0; i < number_of_inputs; i++)
    {
        float input;
        printf("Enter your number = ");
        scanf("%f", &input);

        if (input >= -1 && input <= 1)
        {
            count++;
        }
        
    }
    
    printf("the number of real numbers lying in [-1, 1] is %d\n", count);

    printf("The ratio of real numbers is %d : %d \n", count, number_of_inputs);

    return 0;
}