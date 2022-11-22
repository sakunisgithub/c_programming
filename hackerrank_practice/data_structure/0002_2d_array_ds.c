#include<stdio.h>

int array[6][6];

int hourglassSum();

int main()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    
    int result = hourglassSum();

    printf("%d", result);

    return 0;
}

int hourglassSum()
{
    int sum_of_hourglass[16]; // in a 6X6 array there will always be 16 hourglasses

    int k = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum_of_hourglass[k] = array[i][j] + array[i][j+1] + array[i][j+2] + array[i+1][j+1] + array[i+2][j] + array[i+2][j+1] + array[i+2][j+2];
            k++;
        }
    }
    
    int maximum_sum = sum_of_hourglass[0];

    for (int i = 0; i < 16; i++)
    {
        if (sum_of_hourglass[i] > maximum_sum)
        {
            maximum_sum = sum_of_hourglass[i];
        }
    }
    
    return maximum_sum;
}