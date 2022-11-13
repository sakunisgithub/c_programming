#include<stdio.h>

int main()
{
    int a = 10;
    // printf("%d %d %d", a, ++a, a++);
    // printf("%d %d %d",a++, a, --a);
    // printf("\n%d", a);
    // printf("%d %d %d",--a, a++, --a);
    printf("%d %d %d", --a, a--, a++);
    // The output will be 9 9 9.
    /* Understand the process clearly.
    If there are multiple unary increment or decrement operators in one statement, the operations are done right to left.
    right to left first e a r value calculate hobe
    ebar sob calculate hobar por a r ja value hobe finally seta somosto prefix er jaygay bose jabe
    r postfix r khetre calculation r somoy je value ta esechilo seta hobe */
    // printf("%d\n", a++);
    // printf("%d", a);
    return 0;
}