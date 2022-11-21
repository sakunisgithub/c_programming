#include<stdio.h>
#include<math.h>

void update(int *, int *);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    update(&a, &b);
    printf("%d\n%d", a, b);

    return 0;
}

void update(int * num_1, int * num_2)
{
    int sum = *(num_1) + *(num_2);
    int diff = *(num_1) - *(num_2);

    diff = fabs(diff);

    *(num_1) = sum;
    *(num_2) = diff;
}