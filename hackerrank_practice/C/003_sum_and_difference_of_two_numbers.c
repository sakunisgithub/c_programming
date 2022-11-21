#include<stdio.h>

int main()
{
    int num_1, num_2;
    float first_num, second_num;

    scanf("%d", &num_1);
    scanf("%d", &num_2);
    scanf("%f", &first_num);
    scanf("%f", &second_num);

    printf("%d %d\n", num_1 + num_2, num_1 - num_2);
    printf("%.1f %.1f", first_num + second_num, first_num - second_num);
    return 0;
}