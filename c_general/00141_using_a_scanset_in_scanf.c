#include <stdio.h>
#include <string.h>

int main() 
{
	
    char s[1000];
    printf("\nEnter your string : ");
    scanf("%[^\n]", s); // this accepts any character that is not \n
    
    puts("\nHello, World!\n");
    puts(s);
  	
    return 0;
}