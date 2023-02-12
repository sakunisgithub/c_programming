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
    
    printf("the number of real numbers lying in [-1, 1] is %d", count);


    // float my_array[number_of_inputs];

    // for (int i = 0; i < number_of_inputs; i++)
    // {
    //     printf("enter your number = "); 
    //     scanf("%f", &my_array[i]);

    //     if (my_array[i] >= -1 && my_array[i] <= 1)
    //     {
    //         count++;
    //     }
        
    // }

    // printf("the number of real numbers lying in [-1, 1] is %d\n", count);

    // for (int i = 0; i < number_of_inputs; i++)
    // {
    //     if (my_array[i] >= -1 && my_array[i] <= 1)
    //     {
    //         printf("%f\t", my_array[i]);
    //     }
    // }
        

    return 0;
}