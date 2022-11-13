#include<stdio.h>
#include<math.h>
int main()
{
    int number;
    printf("Enter your decimal number = ");
    scanf("%d", &number);

    if (number == 0)
    {
        printf("\nThe binary number is = %d", 0);
    }
    else
    {

        int copy_number = number;

        // counting how many times the number can be divided by 2 until the dividend becomes 0
        int count = 0;
    
        while (copy_number!=0)
        {
            copy_number = floor(copy_number/2.0);
            count++;
        }

        // creating an array and storing the remainders
        int remainder[count];

        for (int i = 0; i < count; i++)
        {
            remainder[i] = (number)%2;
            number = floor(number/2.0);
        }

        // printing the remainders in reverse order
        printf("\nThe binary number is = ");

        for (int i = count-1 ; i >= 0; i--)
        {
            printf("%d", remainder[i]);
        }
    
    }
    

    return 0;
}