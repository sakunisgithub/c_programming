#include<stdio.h>

int main()
{
    char character, s[105], sen[105];

    scanf("%c", &character);
    scanf("%s", s);
    scanf("\n");
    scanf("%[^\n]c", sen);

    printf("%c\n", character);
    printf("%s\n", s);
    printf("%s", sen);
    return 0;
}