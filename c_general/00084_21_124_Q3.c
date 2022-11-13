#include<stdio.h>

// Question :: Write a program in C to arrange the above data set in descending order by the method of bubble sorting.

void bubble_sort(float*, int);

void swap(float*, float*);

int main()
{
    FILE *pointer1 = NULL;
    pointer1 = fopen("82_21_124_data_set.dat", "r");
    
    char a;
    int c = 0;
    while ( (a = fgetc(pointer1) ) != EOF)
    {
        if (a == '\n')
        {
            c++;
        }
        
    }
    fclose(pointer1);
    
    printf("\nThere are %d numbers in the data set.", c);

    int n;
    printf("\nEnter the number of numbers you want to call = ");
    scanf("%d", &n);

    FILE *pointer2 = NULL;
    pointer2 = fopen("82_21_124_data_set_copy.dat", "r");

    float value[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(pointer2, "%f", &value[i]);
    }

    fclose(pointer2);

    FILE *pointer3 = NULL;
    pointer3 = fopen("84_21_124_output.dat", "w");

    fprintf(pointer3, "The recorded sample is ::: \n");
    for (int i = 0; i < n; i++)
    {
        fprintf(pointer3, "%f\n", value[i]);
    }

    bubble_sort(value, n);

    fprintf(pointer3, "\nThe sorted sample(in descending order) is ::: \n");
    for (int i = n-1; i >= 0; i--)
    {
        fprintf(pointer3, "%f\n", value[i]);
    }
    
    fclose(pointer3);

    return 0;
}

void bubble_sort(float* x, int y)
{
    for (int i = 0; i < y; i++)
    {
        int code = 0;
        for (int j = 0; j < y-1-i; j++)
        {
            if ( *(x+j) > *(x+j+1) )
            {
                swap( (x+j), (x+j+1) );
                code = 1;
            }
            
        }
        if (code == 0)
        {
            break;
        }
        
        
    }
    
}

void swap(float* a, float* b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}