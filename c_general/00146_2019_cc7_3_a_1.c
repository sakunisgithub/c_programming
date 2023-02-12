#include<stdio.h>

float mean(int*, int);

int main()
{
    int numbers[1000];

    printf("Enter the numbers ::\n");
    
    for (int i = 0; i < 1000; i++)
    {
        printf("Enter number[%d] = ", i+1);
        scanf("%d", &numbers[i]);
    }

    float answer;

    answer = mean(numbers, 1000);

    printf("The mean of 1000 numbers is %f\n", answer);
    
    return 0;
}

float mean(int * array, int length)
{
    int sum = 0;

    int i = 0;

    do
    {
        sum += *(array+i);
        i++;        
    } while (i < length);
    
    float required_mean;

    required_mean = (float)sum / (float)length;

    return required_mean;
}