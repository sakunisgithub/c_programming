#include<stdio.h>

// Question :: Write a program in C to arrange the above data set in ascending order by the method of selection sorting and find the median.

void selection_sort(float* , int);

void swap(float*, float*);

int main()
{
    FILE *pointer1 = NULL;
    pointer1 = fopen("00082_21_124_data_set.dat", "r");
    
    char a;
    int c = 0;

    while ( (a = fgetc(pointer1))  != EOF)
    {
        // printf("%c", a);
        if (a == '\n')
        {
            c++;    
        }
    }
    printf("\nThere are %d numbers in the data set.", c);
    fclose(pointer1);

    FILE *pointer2 = NULL;
    pointer2 = fopen("00082_21_124_data_set_copy.dat", "r");

    int count;
    printf("\nEnter the number of numbers you want to call = ");
    scanf("%d", &count);
    

    FILE *pointer3 = NULL;
    pointer3 = fopen("00083_21_124_Q2_output.dat", "w");

    float value[count];
    for (int i = 0; i < count; i++)
    {
        fscanf(pointer2, "%f", &value[i]);
    }

    fclose(pointer2);
    

    fprintf(pointer3, "The recorded sample is:::\n");
    for (int i = 0; i < count; i++)
    {
        fprintf(pointer3, "%f\n", value[i]);
    }

    selection_sort(value, count);

    fprintf(pointer3, "\n");
    
    fprintf(pointer3, "The sorted sample(in ascending order) is:::\n");
    for (int i = 0; i < count; i++)
    {
        fprintf(pointer3, "%f\n", value[i]);
    }
    
    if (count%2 != 0)
    {
        fprintf(pointer3, "\nThe median of the sample is %f", value[count/2]);
    }
    else if (count%2 == 0)
    {
        fprintf(pointer3, "\nThe median of the sample is %f", ( ( value[ (count/2) -1 ] + value[count/2] ) / 2.0 ) );
    }
    
    fclose(pointer3);
    
    return 0;
}

void selection_sort(float* x, int y)
{
    for (int i = 0; i < y; i++)
    {
        for (int j = i+1; j < y; j++)
        {
            if ( *(x+i) > *(x+j) )
            {
                swap( (x+i), (x+j) );
            }
            
        }
        
    }
    
}

void swap(float* m, float* n)
{
    float temp;
    temp = *m;
    *m = *n;
    *n = temp;
}