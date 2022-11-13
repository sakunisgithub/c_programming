#include<stdio.h>
#include<string.h>

int main()
{
    int testcases;
    scanf("%d", &testcases);

    char left_hand_size[55];
    char right_hand_size[55]; // given that the length of size does not exceed 50
    // keeping the size exactly 50 will generate errors when the string size becomes 50 because strings require to have a null character at the end 
    
    int x, y;

    int output[testcases];

    for (int i = 0; i < testcases; i++)
    {
        scanf("%s", left_hand_size);
        scanf("%s", right_hand_size);

        x = strlen(left_hand_size);
        y = strlen(right_hand_size);

        if (left_hand_size[x-1] > right_hand_size[y-1])
        {
            output[i] = -1;
        }
        else if (left_hand_size[x-1] < right_hand_size[y-1])
        {
            output[i] = 1;
        }
        else if (left_hand_size[x-1] == 'L' && (x < y))
        {
            output[i] = -1;
        }
        else if (left_hand_size[x-1] == 'L' && (x > y))
        {
            output[i] = 1;
        }
        else if (left_hand_size[x-1] == 'S' && (x > y))
        {
            output[i] = -1;
        }
        else if (left_hand_size[x-1] == 'S' && (x < y))
        {
            output[i] = 1;
        }
        else
        {
            output[i] = 0;
        }
    }
    
    for (int i = 0; i < testcases; i++)
    {
        if (output[i] == -1)
        {
            printf("<\n");
        }
        else if (output[i] == 1)
        {
            printf(">\n");
        }
        else
        {
            printf("=\n");
        }
    }
    
    
    return 0;
}

// https://codeforces.com/problemset/problem/1741/A

/* 
-1 indicates <
1 indicates >
0 indicates =
by ASCII values L < M < S
but by the problem symbols, L > M > S
when the end characters are equal, if it is L, the string with longer length is the larger shirt size
and if it is S, the string with longer length is the smaller shirt size
*/