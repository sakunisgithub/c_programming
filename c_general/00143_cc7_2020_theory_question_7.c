#include<stdio.h>

int main()
{
    int number_of_even_numbers = 0;

    for(int i = 1; i <= 60; i++)
    {
       if (i % 2 == 0)
       {
            number_of_even_numbers++;
       } 
    }

    float percentage = ((float)(number_of_even_numbers)/(float)(60)) * (float)100;

    printf("The proportion of even numbers among first 60 natural numbers is (%d/60) i.e. %f percent", number_of_even_numbers, percentage);

    return 0;
}
