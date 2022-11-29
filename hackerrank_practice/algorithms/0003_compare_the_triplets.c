#include<stdio.h>

int main()
{
    int Alice[3], Bob[3], score[2];

    score[0] = score[1] = 0;
    
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &Alice[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &Bob[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        if (Alice[i] > Bob[i])
        {
            score[0]++;
        }
        else if (Alice[i] < Bob[i])
        {
            score[1]++;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        printf("%d ", score[i]);
    }
    
    return 0;
}