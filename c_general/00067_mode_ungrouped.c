#include<stdio.h>

int main()
{   
    // asking total number of observations
    int n;
    printf("Enter total number of observations you want to enter : ");
    scanf("%d", &n);
    

    // taking observations as from the user
    float observation[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter observation number %d = ", i+1);
        scanf("%f", &observation[i]);

    }
    

    // taking the code
    float code;
    printf("\nEnter code . Your code must be an integer that is NOT equal to any of the observations. = ");
    scanf("%f", &code);


    // printitng the observations
    printf("\nThe observations are :: ");
    for (int i = 0; i < n; i++)
    {
        printf("\n%f", observation[i]);
    }


    // making a copy of the observations(to calculate total number of unique observations)  I could have used the array observation[n] to calculate total number of unique observations. While I am counting, I am replacing the repeated observations by the code. So after counting, the main array observation[n] would get spoiled with and I would loose the initial observations. So I created a copy of the main array and I am performing operations on that copy.
    float obs_copy[n];
    for (int i = 0; i < n; i++)
    {
        obs_copy[i] = observation[i];
    }


    // changing the repeated observations with code
    for (int i = 0; i < n; i++)
    {
        if (obs_copy[i] != code)
        {
            for (int j = i+1; j < n; j++)
            {
                if (obs_copy[i] == obs_copy[j])
                {
                    obs_copy[j] = code;
                }
            }
        }
    }

    printf("\n");

    // printing the coded set of observations(only to check whether the replacement with the code has been successful or not)
    /* for (int i = 0; i < n; i++)
    {
        printf("\n%f", obs_copy[i]);
    } */
    //uncomment line number 61,62,63,64 to print the coded set of observations


    // counting and printing total number of unique observations
    int a = 0; // a is the integer that counts total number of unique observations
    for (int i = 0; i < n; i++)
    {
        if (obs_copy[i] != code)
        {
            a++;  
        }
        
    }
    printf("\nTotal number of unique observations is %d", a);


    // counting the frequencies of the unique observations
    int frequency[a], k = 0; // as there are 'a' many unique obervations, I need a frequency array capable to hold 'a' many frequencies only.
    
    int count;

    for (int i = 0; i < n; i++)
    {
        count = 1;
        if (observation[i] != code)
        {
            for (int j = i+1; j < n; j++)
            {
                if (observation[i] == observation[j])
                {
                    count++;
                    observation[j] = code;
                }
            
            }
            frequency[k] = count;
            k++; // k is the integer that helps us to access the indexes of frequency[a]
        }
         
        
    }


    // making an array with the unique observations only (and printing it only to check whether sorting the unique observaitons has been successful or not)
    float unique_observation[a];
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (observation[i] != code)
        {
            unique_observation[m] = observation[i];
            m++;
        }
        
    }
    /* printf("\n");
    printf("\nThe unique observations are ");
    for (int i = 0; i < a; i++)
    {
        printf("\n%f", unique_observation[i]);
    } */
    // uncomment line number 120,121,122,123,124,125 to print the unique observations


    // printing the frequencies of the unique observations only to check whether calculating the frequencies has been successful or not)
    /* printf("\n");
    printf("\nThe corresponding frequencies are ");
    for (int i = 0; i < a; i++)
    {
        printf("\n%d", frequency[i]);
    } */
    // uncomment line number 130,131,132,133,134,135 to print the unique observations
    

    // printing the unique observations and their corresponding frequencies in tabular form
    printf("\n");
    printf("\nObservation     Frequency");
    for (int i = 0; i < a; i++)
    {
        printf("\n%f          %d", unique_observation[i], frequency[i]);
    }
    

    // determining and printing the maximum frequency
    int fmax = frequency[0];
    for (int i = 1; i < a; i++)
    {
        if (fmax <= frequency[i])
        {
            fmax = frequency[i];
        }
        
    }
    printf("\n");
    printf("\nThe maximum frequency is %d", fmax);


    // counting how many times maximum frequency appears and catching the index where maximum frequency occurs
    int fmax_app = 0;
    for (int i = 0; i < a; i++)
    {
        if (frequency[i] == fmax)
        {
            fmax_app++;
        }
        
    }
    
    int index[fmax_app];
    int p = 0;
    for (int i = 0; i < a; i++)
    {
        if (frequency[i] == fmax)
        {
            index[p] = i;
            p++;
        }
        
    }


    // printing the index no(s) of the frequency array where mode appears(only to verify whether indexes have been caught successfully or not)
    
    /* for (int i = 0; i < fmax_app; i++)
    {
        printf("\n%d", index[i]);
    } */
    // uncomment line no 174,175,176,177 to print the index numbers


    // printing the mode
    printf("\n");
    printf("\nMode  ::");
    for (int i = 0; i < fmax_app; i++)
    {
        printf("\t%f", unique_observation[index[i]]);
    }
  
    
    return 0;
}