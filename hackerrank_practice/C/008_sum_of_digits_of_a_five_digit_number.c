#include<stdio.h>

int main()
{
    int number;
    scanf("%d", &number);
    
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        int temp = number % 10; 
        sum += temp;
        number /= 10;
    }
    
    printf("%d", sum);

    return 0;
}