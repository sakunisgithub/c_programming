#include<stdio.h>
#include<string.h>

void slice(char*, int, int);

int main()
{
    char string[1000];
    printf("\nEnter your string : ");
    gets(string);

    printf("\nThe length of your string is %d", strlen(string));

    int m, n;
    printf("\nEnter the start position of slice = ");
    scanf("%d", &m);
    printf("\nEnter the end position of slice = ");
    scanf("%d", &n);

    slice(string, m, n);

    printf("\nYour sliced string is : ");
    puts(string);


    return 0;
}

void slice(char* A, int start, int end)
{
    int i = 0;

    start -= 1;
    end -= 1;

    while (start <= end)
    {
        *(A+i) = *(A+start);
        i++;
        start++;
    }

    for (;i < 1000; i++)
    {
        *(A+i) = '\0';
    }
}