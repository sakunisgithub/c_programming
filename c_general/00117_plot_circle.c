#include<stdio.h>

int main()
{
    float radius;
    printf("\nEnter radius = ");
    scanf("%f", &radius);

    for (int i = -radius; i <= radius; i++)
    {
        for (int j = -radius; j <= radius; j++)
        {
            float x = i;
            float y = j;
            ( x*x + y*y == radius*radius) ? (printf("# ")) : (printf("  "));
        }
        printf("\n");
    }
    
    return 0;
}