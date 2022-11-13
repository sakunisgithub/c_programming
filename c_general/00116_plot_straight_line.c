#include<stdio.h>

int main()
{
    float slope, intercept;
    printf("\nEnter slope = ");
    scanf("%f", &slope);
    printf("\nEnter intercept = ");
    scanf("%f", &intercept);
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            int x = j;
            int y = 20 - i;
            (y == slope*x + intercept) ? (printf("*")) : (printf(" "));
        }
        printf("\n");
        
    }
    for (int i = 0; i < 20; i++)
    {
        printf("__");
    }
    
    
    return 0;
}