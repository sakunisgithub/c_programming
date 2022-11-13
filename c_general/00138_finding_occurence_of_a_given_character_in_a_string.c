#include<stdio.h>
#include<string.h>

int main()
{
    char string[1000];
    printf("\nEnter your string : ");
    gets(string);

    char find;
    printf("\nEnter the character you want to count the occurrence of = ");
    scanf("%c", &find);
    
    int count, length = strlen(string);

    for (int i = 0; i < length; i++)
    {
        if (string[i] == find)
        {
            count++;
        }
        
    }

    printf("\nThe character '%c' is %d times in the string", find, count);
    
    return 0;
}