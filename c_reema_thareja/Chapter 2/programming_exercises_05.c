#include<stdio.h>
#include<string.h>

int main()
{
    char text[10000];

    printf("\nEnter your text : ");
    gets(text);

    int length = strlen(text);
    
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u')
        {
            count++;
        }
    }
    
    printf("\nThere is/are %d vowels in the text", count);
    return 0;
}