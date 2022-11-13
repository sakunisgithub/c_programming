#include<stdio.h>

int main()
{
    for (int i = -10; i <= 10; i++)
    {
        for (int j = 0; j <= 10; j++)
        {
            float x = i;
            float y = j;
            ( x*x - y == 0) ? (printf("#")) : (printf(" "));
        }
        printf("\n");
    }
    
    return 0;
}