#include<stdio.h>

int main()
{
    float major, minor;
    printf("\nEnter length of major axis = ");
    scanf("%f", &major);
    major /= 2;
    printf("\nEnter length of minor axis = ");
    scanf("%f", &minor);
    minor /= 2;
    for (int i = -major; i <= major; i++)
    {
        for (int j = -minor; j <= minor; j++)
        {
            float x = i;
            float y = j;
            ( ( ( (x*x)/(major*major) ) + ( (y*y)/(minor*minor) ) ) == 1 ) ? (printf("* ")) : (printf("  "));
        }
        printf("\n");
    }
    
    return 0;
}