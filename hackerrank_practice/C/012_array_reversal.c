#include<stdio.h>

int main()
{
    int length;
    scanf("%d", &length);

    int array[length];

    for (int i = 0; i < length; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < length/2; i++)
    {
        int temp = array[i];
        array[i] = array[length - i - 1];
        array[length - i - 1] = temp;
    }

    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    
    return 0;
}