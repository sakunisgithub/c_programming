#include<stdio.h>

int main()
{
    char pattern[3][3];

    gets(pattern[0]);
    gets(pattern[1]);
    gets(pattern[2]);

    // could have used nested loops to scan the 2d matrix named pattern, but that is not working properly in codeforces

    int code;

    if (pattern[0][0] != pattern[2][2])
    {
        code = 0;
        goto output;
    }
    else if (pattern[0][2] != pattern[2][0])
    {
        code = 0;
        goto output;
    }
    else if (pattern[0][1] != pattern[2][1])
    {
        code = 0;
        goto output;
    }
    else if (pattern[1][0] != pattern[1][2])
    {
        code = 0;
        goto output;
    }
    else
    {
        code = 1;
        goto output;
    }
    
    output :
    if (code == 1)
    {
        printf("YES");
    }
    else if (code == 0)
    {
        printf("NO");
    }
     
    return 0;
}

// https://codeforces.com/problemset/problem/12/A