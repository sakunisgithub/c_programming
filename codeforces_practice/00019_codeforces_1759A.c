#include<stdio.h>
#include<string.h>

int main()
{
    int testcases;
    scanf("%d", &testcases);

    int output[testcases];

    for (int i = 0; i < testcases; i++)
    {
        char string[55];

        scanf("%s", string);
        
        if (strlen(string) == 1)
        {
            if (string[0] == 'Y' || string[0] == 'e' || string[0] == 's')
            {
                output[i] = 1;
            }
            else
            {
                output[i] = 0;
            }
        }
        else 
        { 
            int j;
            for (j = 0; j < strlen(string) - 1; j++)
            {
                if (string[j] != 'Y' && string[j] != 'e' && string[j] != 's')
                {
                    output[i] = 0;
                    break;
                }
                else if (string[j] == 'Y' && string[j+1] != 'e')
                {
                    output[i] = 0;
                    break;
                }
                else if (string[j] == 'e' && string[j+1] != 's')
                {
                    output[i] = 0;
                    break;
                }
                else if (string[j] == 's' && string[j+1] != 'Y')
                {
                    output[i] = 0;
                    break;
                }
            }     

            if (j == strlen(string) - 1)
            {
                output[i] = 1;
            }
        } 

    }
    
    for (int i = 0; i < testcases; i++)
    {
        if (output[i])
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        
    }
    
    return 0;
}

// https://codeforces.com/problemset/problem/1759/A