#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char string[1005];

    scanf("%s", string);

    int * array = (int *) calloc(10, sizeof(int));

    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '0')
        {
            array[0]++;
        }
        else if (string[i] == '1')
        {
            array[1]++;
        }
        else if (string[i] == '2')
        {
            array[2]++;
        }
        else if (string[i] == '3')
        {
            array[3]++;
        }
        else if (string[i] == '4')
        {
            array[4]++;
        }
        else if (string[i] == '5')
        {
            array[5]++;
        }
        else if (string[i] == '6')
        {
            array[6]++;
        }
        else if (string[i] == '7')
        {
            array[7]++;
        }
        else if (string[i] == '8')
        {
            array[8]++;
        }
        else if (string[i] == '9')
        {
            array[9]++;
        }
            
    }
    
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    
    free(array);

    return 0;
}