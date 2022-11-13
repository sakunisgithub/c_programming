#include<stdio.h>

int main()
{
    int a = 5, b = 10;
    int x = (a < 3) && (b++);
    printf("%d %d", x, b);
    // the output will be 0 10
    printf("\n");
    int c = 5, d = 10;
    int y = (c > 3) && (d++);
    printf("%d %d", y, d);
    // the output will be 1 11
    return 0;
}