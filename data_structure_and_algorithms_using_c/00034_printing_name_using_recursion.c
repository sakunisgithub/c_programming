#include<stdio.h>

void print_name();

int main()
{
    print_name();

    return 0;
}

void print_name()
{
    static int count = 0;

    if (count == 5) 
    {
        return;
    } 
    else 
    {
        printf("sakuni\n");
        count++;
        print_name();
    }
     
}
