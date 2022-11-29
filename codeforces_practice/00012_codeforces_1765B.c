// this gives correct output in my laptop (gcc 12.2.0), but on codeforces it gives incorrect output, don't know why
#include<stdio.h>

int main()
{
    int testcases;
    scanf("%d", &testcases);

    int output[testcases];

    for (int i = 0; i < testcases; i++)
    {
        int length;
        scanf("%d", &length);

        char word[length + 1];

        fflush(stdin);
        gets(word);

        if (length % 3 == 0 || length % 3 == 1)
        {
            if (length == 1)
            {
                output[i] = 1;
            }
            else
            {
                output[i] = 1;

                for (int j = 1; j < length; j = j+3)
                {
                    if (word[j] != word[j+1])
                    {
                        output[i] = 0;
                        break;
                    }
                }
            }
        }
        else if (length % 3 == 2)
        {
            output[i] = 0;
        }
    }

    for (int i = 0; i < testcases; i++)
    {
        if (output[i] == 1)
        {
            printf("YES\n");
        }
        else if (output[i] == 0)
        {
            printf("NO\n");
        }
    }
    
        
    return 0;
}

// https://codeforces.com/problemset/problem/1765/B