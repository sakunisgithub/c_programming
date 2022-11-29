#include<stdio.h>
#include<stdlib.h>

int main()
{
    int length;
    scanf("%d", &length);

    int * array = (int *) malloc(length * sizeof(int));

    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    
    printf("%d", sum);

    free(array);

    return 0;
}