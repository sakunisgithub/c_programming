#include<stdio.h>
#include<string.h>

#define for_loop(variable, initial_value, maximum_value) for(variable = initial_value; variable < maximum_value; variable++)

int main()
{
    char string[1000];
    printf("\nEnter your string : ");
    gets(string);

    int length = strlen(string);
    
    int i = 0;
    char encrypted_string[1000];

    for_loop(i, 0, length)
    {
        encrypted_string[i] = string[i] + 1;
    }

    printf("\nThe encrypted string is : ");
    puts(encrypted_string);

    char decrypted_string[1000];

    for_loop(i, 0, length)
    {
        decrypted_string[i] = encrypted_string[i] - 1;
    }

    printf("\nThe decrypted string is : ");
    puts(decrypted_string);
    

    
    return 0;
}