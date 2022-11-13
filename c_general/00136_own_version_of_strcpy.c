#include<stdio.h>

void my_strcpy(char*, char*);

int main()
{
    char string[1000];
    printf("\nEnter your string : ");
    gets(string);

    printf("\nYour string is : ");
    puts(string);

    char copy_string[1000];

    my_strcpy(copy_string, string);

    printf("\nThe copied string is : ");
    puts(copy_string);
    
    return 0;
}

void my_strcpy(char* target, char* source)
{
    for (int i = 0; i < 1000; i++)
    {
        *(target+i) = *(source+i);
    }
    

}