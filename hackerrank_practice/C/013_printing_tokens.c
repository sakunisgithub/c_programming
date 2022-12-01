#include<stdio.h>
#include<string.h>

int main()
{
    char sentence[1005];

    scanf("%[^\n]", sentence);

    for (int i = 0; i < strlen(sentence); i++)
    {
        if (sentence[i] == ' ')
        {
            printf("\n");
        }
        else
        {
            printf("%c", sentence[i]);
        }
    }
    
    return 0;
}