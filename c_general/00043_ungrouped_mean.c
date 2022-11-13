#include<stdio.h>

// Without asking the user the total number of observations

// pre-requisite : the user must have an overview of the data and set the stopper code accordingly

/* guideline to set stopper code : have an overview of the data and set a number as the stopper code 
such that the number is not present in the data as an observation 
i.e. the stopper code must not match with any of the observations. */

int main(){

    int number = 1 ;
    float sum = 0, code, observation;

    printf("Enter Your Stopper Code : \n");
    scanf("%f", &code);

    printf("Enter the first observation : \n");
    scanf("%f", &observation);
    sum = sum + observation;

    do
    {
        printf("Enter code or Enter next observation : \n");
        scanf("%f", &observation);
        if (observation == code)
            {break;}
        else 
            {
            number = number + 1;
            sum = sum + observation;
            }
        
    } while (observation != code);

    if (observation == code)
    {
        printf("The required mean is %f", sum/number);
    }
    return 0;
}