#include<stdio.h>

int simple_array_sum(int *, int);

int main()
{
    int n;
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("%d", simple_array_sum(array, n));
    
    return 0;
}

int simple_array_sum(int * array, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(array + i);
    }
     
    return sum;
}