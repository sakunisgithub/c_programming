#include<stdio.h>
#include<string.h>

int main()
{
    char string[1000];
    printf("\nEnter your string : ");
    gets(string);

    char find;
    printf("\nEnter the character you want to find = ");
    scanf("%c", &find);

    int code = 0, length = strlen(string);

    for (int i = 0; i < length; i++)
    {
        if (string[i] == find)
        {
            code = 1;
            break;
        }
        
    }

    if (code == 0)
    {
        printf("\nSorry!!! The given characte is not found in the string");
    }
    else if (code == 1)
    {
        printf("\nThe given character is present in the string");
    }
    
    
    return 0;
}