#include<stdio.h>

// Without asking the user the total number of classes

// pre-requisite : the user must have an overview of the data and set the stopper code accordingly

/* guideline to set the stopper code : have an overview of the data and set a number as the stopper code such that
the number does not match with any of the lower or upper class boundaries or with any of the class frequencies. */

int main(){
    int class = 1;

    float code, lower, upper, frequency, mark, product, sum = 0, total_frequency = 0;

    printf("Enter Your Stopper Code : \n");
    scanf("%f", &code);

    printf("Enter the first lower class boundary :\n");
    scanf("%f", &lower);

    printf("Enter the first upper class boundary :\n");
    scanf("%f", &upper);

    mark = (lower + upper)/2.0;

    printf("Enter the corresponding frequency :\n");
    scanf("%f", &frequency);

    total_frequency = total_frequency + frequency;

    product = mark * frequency;

    sum = sum + product;

    do
    {
        printf("Enter code or Enter the next lower class boundary :\n");
        scanf("%f", &lower);
        if (lower == code && class == 1)
            {printf("The required mean is %f", mark);}
        else if (lower == code && class > 1)
            {break;}
        else
            {class++;

            printf("Enter the next upper class boundary :\n");
            scanf("%f", &upper);

            mark = (lower + upper)/2.0;

            printf("Enter the corresponding frequency :\n");
            scanf("%f", &frequency);

            total_frequency = total_frequency + frequency; 

            product = mark * frequency;

            sum = sum + product;

            };
        
    } while (lower != code);

    if (lower == code && class > 1)
    {
        printf("The required mean is %f", sum/total_frequency);
    }
    
    
    return 0;
}