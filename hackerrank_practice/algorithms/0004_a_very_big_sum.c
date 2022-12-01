#include<stdio.h>

unsigned long long int a_very_big_sum(unsigned long long int *, int);

int main()
{
    int length;
    scanf("%d", &length);

    unsigned long long int array[length];

    for (int i = 0; i < length; i++)
    {
        scanf("%llu", &array[i]);
    }

    printf("%llu", a_very_big_sum(array, length));
    
    return 0;
}

unsigned long long int a_very_big_sum(unsigned long long int * arr, int n)
{
    unsigned long long int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += *(arr + i);
    }

    return sum;
    
}