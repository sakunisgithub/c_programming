#include <stdio.h>

int main()
{

    int a;
    float r;

    printf("Enter the year\n");
    scanf("%d", &a);

    if (a % 4 != 0)
    {
        printf("It is a common year.");
    }
    else if (a % 100 != 0)
    {
        printf("It is a leap year.");
    }
    else if (a % 400 != 0)
    {
        printf("It is a common year.");
    }
    else
    {
        printf("It is a leap year.");
    }
    return 0;
}