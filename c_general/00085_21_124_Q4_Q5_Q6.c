#include<stdio.h>
#include<math.h>

// Question :: Write a program in C to construct a frequency distribution table containing cumulative frequencies( > type) and relative frequencies using the above data set 
// Question :: Write a program in C to construct a frequency distribution table using the above data set and to compute the grouped median from the table.
// Question :: Write a program in C to construct a frequency distribution table using the above data set and to compute the grouped mode from the table.


void bubble_sort(float*, int);

void swap(float*, float*);

int main()
{
    FILE *pointer1 = NULL;
    pointer1 = fopen("82_21_124_data_set.dat", "r");

    char a;
    int c = 0;
    while ( (a = fgetc(pointer1)) != EOF)
    {
        if (a == '\n')
        {
            c++;
        }
    }
    
    printf("\nThere are %d numbers in the data set.", c);
    fclose(pointer1);

    FILE *pointer2 = NULL;
    pointer2 = fopen("82_21_124_data_set_copy.dat", "r");

    int n;
    printf("\nEnter the number of numbers you want to call = ");
    scanf("%d", &n);
    
    float value[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(pointer2, "%f", &value[i]);
    }
    
    fclose(pointer2);

    int length;

    printf("\nEnter the common length of the classes = ");
    scanf("%d", &length);

    FILE *pointer3 = NULL;
    pointer3 = fopen("85_21_124_output.dat", "w");

    fprintf(pointer3, "The recorded sample is ::: \n");
    for (int i = 0; i < n; i++)
    {
        fprintf(pointer3, "%f\n", value[i]);
    }
    
    bubble_sort(value, n);

    fprintf(pointer3, "\nThe sorted sample(in ascending order) is ::: \n");
    for (int i = 0; i < n; i++)
    {
        fprintf(pointer3, "%f\n", value[i]);
    }

    fprintf(pointer3, "\nThe least observation is %f", value[0]);
    fprintf(pointer3, "\nThe highest observation is %f", value[n-1]);
    fprintf(pointer3, "\nThe range of the observations is %f", (value[n-1] - value[0]) );

    float A = floor( value[0] );
    float B = floor( value[n-1] ) + 1;
    int class = (B - A)/length; // class denotes the number of classes possible

    float lower[class], upper[class], relative_frequency[class];
    int frequency[class], cumulative_frequency[class], cum_freq[class];

    for (int i = 0; i < class; i++)
    {
        lower[i] = A + i*length;
        upper[i] = lower[i] + length;
    }
    
    for (int j = 0; j < class; j++)
    {
        frequency[j] = 0;

        for (int i = 0; i < n; i++)
        {
            if ( (value[i] >= lower[j]) && (value[i] < upper[j]) )
            {
                frequency[j]++;
            }
        }
        
    }

    int total_frequency = 0;
    for (int i = 0; i < class; i++)
    {
        total_frequency = total_frequency + frequency[i];
    }
    

    cumulative_frequency[class-1] = frequency[class - 1];
    for (int i = class - 2; i >= 0; i--)
    {
        cumulative_frequency[i] = cumulative_frequency[i+1] + frequency[i];
    }

    cum_freq[0] = frequency[0];
    for (int i = 1; i < class; i++)
    {
        cum_freq[i] = cum_freq[i-1] + frequency[i];
    }
    
    
    for (int i = 0; i < class; i++)
    {
        relative_frequency[i] = (float)frequency[i] / (float)total_frequency;
    }

    fprintf(pointer3, "\n");
    fprintf(pointer3, "L.C.B.  \t\t  U.C.B.  \t\tFrequency\t Relative Frequency \t Cumulative Frequency(< type) \t Cumulative Frequency(> type)\n");
    for (int i = 0; i < class; i++)
    {
        fprintf(pointer3, "%2.6f \t\t %2.6f \t\t %4d \t\t\t %2.6f \t\t\t\t\t %4d \t\t\t\t\t\t\t %4d\n", lower[i], upper[i], frequency[i], relative_frequency[i],cum_freq[i], cumulative_frequency[i]);

    }

    fprintf(pointer3, "The total frequency is %d", total_frequency);

    float N = total_frequency/2.0;
    int index1;  // index1 denotes the index of the median class

    for (int i = 0; i < class; i++)
    {
        if ((cum_freq[i] == N) || (cum_freq[i] > N))
        {
            index1 = i;
            break;
        }
        
    }

    float median = lower[index1] + ( ( ( N - cum_freq[index1-1] ) * ( upper[index1] - lower[index1] ) ) / frequency[index1] );
    
    fprintf(pointer3, "\nThe median of the sample is %f", median);

    int fmax = frequency[0];
    int index2; // index will store the index of the maximum frequency in the frequency array
    // the first class is supposed to not have the maximum frequency
    // if the first class has the maximum frequency, the formula will not stand good
    int code = 0;
    for (int i = 1; i < class; i++)
    {
        if (frequency[i] >= fmax)
        {
            fmax = frequency[i];
            index2 = i;
            code = 1;
        }
        
    }
    if (code == 0)
    {
        index2 = 0;
    }
    

    float C, D;

    C = ( upper[index2] - lower[index2] ) * ( frequency[index2] - frequency[index2-1] );

    D = 2*frequency[index2] - frequency[index2-1] - frequency[index2+1];

    fprintf(pointer3, "\nThe mode of the sample is = %f", ( lower[index2] + (C/D) ) );
    


    fprintf(pointer3, "\nL.C.B. and U.C.B. stand for Lower Class Boundary and Upper Class Boundary respectively.");
    
    fclose(pointer3);

    
    return 0;
}

void bubble_sort(float* x, int y)
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < y-1-i; j++)
        {
            if ( *(x+j) > *(x+j+1) )
            {
                swap( (x+j), (x+j+1) );
            }
            
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