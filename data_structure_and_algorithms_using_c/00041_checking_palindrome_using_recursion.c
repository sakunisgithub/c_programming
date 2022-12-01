#include<stdio.h>
#include<stdbool.h>

bool check_palindrome(char *, int, int);

int main()
{
    char string[] = "abcd12321dcba";

    printf("%d", check_palindrome(string, 13, 0));

    return 0;
}

bool check_palindrome(char * s, int n, int index)
{
    if (index >= n/2)
    {
        return true;
    }

    if (*(s + index) != *(s + n - index - 1))
    {
        return false;
    }
    else
    {
        return check_palindrome(s, n, index + 1);
    }
    
        
}