#include<stdio.h>

int main()
{
    int testcases;
    scanf("%d", &testcases);

    int output[testcases];

    for (int i = 0; i < testcases; i++)
    {
        int numbers[3];

        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &numbers[j]);
        }

        int min, max;

        (numbers[0] >= numbers[1]) ? ((numbers[0] >= numbers[2]) ? (max = numbers[0]) : (max = numbers[2])) : ((numbers[1] >= numbers[2]) ? (max = numbers[1]) : (max = numbers[2]));

        (numbers[0] <= numbers[1]) ? ((numbers[0] <= numbers[2]) ? (min = numbers[0]) : (min = numbers[2])) : ((numbers[1] <= numbers[2]) ? (min = numbers[1]) : (min = numbers[2]));

        for (int j = 0; j < 3; j++)
        {
            if (numbers[j] != min && numbers[j] != max)
            {
                output[i] = numbers[j];
            }
        }
    }

    for (int i = 0; i < testcases; i++)
    {
        printf("%d\n", output[i]);
    }
    
    return 0;
}