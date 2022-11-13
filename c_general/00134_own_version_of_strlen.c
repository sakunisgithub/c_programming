#include<stdio.h>
#include<string.h>

int my_strlen(char*);

int main()
{
	char string[1000];
	printf("\nEnter your string : ");
	gets(string); 

	printf("\nYour string is : ");
	puts(string);

	int length = my_strlen(string);

	printf("\n(using the user defined function) The length of your string is %d", length);

	printf("\n(using the in-built function) The length of your string is %d", strlen(string));
	
	return 0;
}

int my_strlen(char* A)
{
	int i = 0, count = 0;

	while (*(A+i) != '\0')
	{
		count++;
		i++;
	}

	return count;
	
}