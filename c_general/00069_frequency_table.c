#include<stdio.h>
#include<math.h>
// using the following program, you can do both of the following:::
//    1. have a source file, take inputs from it and perform calculation
//    2. take observations as input from the user and perform calculation
// the following program is currently set for case 1.
// comment and uncomment codes perfectly to make this program suitable for case 2.

void bubble_sort(int*, int);

void swap(int*, int*);

int main()
{
    // calling observations from the source file
    FILE* pointer1 = NULL;
    pointer1 = fopen("00069_source_file.dat", "r");
    // pointer1 = fopen("69_source_file.dat", "w");

    int n;
    printf("Enter total number of observations you want to call : ");
    scanf("%d", &n);

    // int n;
    // printf("\nEnter total number of observations = ");
    // scanf("%d", &n);

    int observation[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(pointer1, "%d", &observation[i]);
    }


    // for (int i = 0; i < n; i++)
    // {
    //     printf("\nEnter observation no %d = ", i+1);
    //     scanf("%d", &observation[i]);
    // }
    

    // int observation[n];
    // for (int i = 0; i < n; i++)
    // {
    //     fprintf(pointer1, "%d\t", observation[i]);
    //     if ((i+1)%5 == 0)
    //     {
    //         fprintf(pointer1, "\n");
    //     }
        
    // }

    fclose(pointer1);

    // pointer1 = fopen("69_source_file.dat", "r");

    FILE* pointer2 = NULL;
    pointer2 = fopen("00069_output_file.dat", "w");

    // printing the observations in the output file
    fprintf(pointer2, "The observations are \n");
    for (int i = 0; i < n; i++)
    {
        fprintf(pointer2, "%d\t", observation[i]);
        if ((i+1)%5 == 0)
        {
            fprintf(pointer2, "\n");
        }
    }
    
    // sorting the array of the observations
    bubble_sort(observation, n);

    // printing the sorted observations
    fprintf(pointer2, "The sorted observations are \n");
    for (int i = 0; i < n; i++)
    {
        fprintf(pointer2, "%d \t", observation[i]);
        if ((i+1)%5 == 0)
        {
            fprintf(pointer2, "\n");
        }
    }
    

    // printing the maximum and minimum observations in the output file
    fprintf(pointer2, "\nThe minimum observation is %d", observation[0]);

    fprintf(pointer2, "\nThe maximum observation is %d", observation[n-1]);

    // taking the class length as an input from the user
    int t;
    printf("Enter desired class length : ");
    scanf("%d", &t);

    int a, b, h;
    // a denotes the lower class limit of the first class
    // b denotes the upper class limit of the final class
    a = floor( observation[0]/10 ) * 10; // we are dividing the least observation by 10 and then we are multiplying by 10 assuming that the observations are 2 digit numbers. If they were 3 digit numbers we would have replaced 10 by 100 and so on for higher digit numbers.
    b = floor( observation[n-1]/10 + 1) * 10;
    h = (b-a)/t; // h denotes total number of classes

    int lower[h], upper[h], frequency[h], freq_less[h], freq_greater[h];

    for (int i = 0; i < h; i++)
    {
        lower[i] = a + i*t; // making the lower boundary
        upper[i] = lower[i] + t; // making the upper boundary
        frequency[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (observation[j] >= lower[i] && observation[j] < upper[i])
            {
                frequency[i]++;
            }
            // if observation lies within the range, frequency gets increased by 1
            
        }
        
    }
    
    // calculating total frequency
    int total_frequency = 0;
    for (int i = 0; i < h; i++)
    {
        total_frequency = total_frequency + frequency[i];
    }

    // calculating less than type cumulative frequency
    freq_less[0] = frequency[0];
    for (int i = 1; i < h; i++)
    {
        freq_less[i] = freq_less[i-1] + frequency[i];
    }

    // calculating greater than type cumulative frequency
    freq_greater[h-1] = frequency[n-1];
    for (int i = h-2; i >= 0; i--)
    {
        freq_greater[i] = freq_greater[i+1] + frequency[i];
    }

    fprintf(pointer2, "\nClass Intervals \t\t Frequency \t\t Cumulative Frequency(<) \t\t Cumulative Frequency(>)\n");
    for (int i = 0; i < h; i++)
    {
        fprintf(pointer2, "%4d-%4d \t\t\t\t\t %4d \t\t\t\t\t\t %4d \t\t\t\t\t\t\t %4d \n", lower[i], upper[i], frequency[i], freq_less[i], freq_greater[i]);
    }

    fprintf(pointer2, "\nTotal Frequency = %d", total_frequency);


    // fclose(pointer1);
    fclose(pointer2);





    return 0;
}

void bubble_sort(int* A, int a)
{
    for (int i = 0; i < a-1; i++)
    {
        int sort_code = 0;
        for (int j = 0; j < a-1-i; j++)
        {
            if ( *(A+j) > *(A+j+1) )
            {
                swap( (A+j), (A+j+1) );
                sort_code = 1;
            }
            
        }
        if (sort_code == 0)
        {
            break;
        }
        
        
    }
    
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}