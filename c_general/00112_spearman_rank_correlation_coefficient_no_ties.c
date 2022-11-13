#include<stdio.h>

// this program is limited to finding the spearman rank correlation on the basis of 2 characteristics only

void standard_rank(int*, int, int*); // as there are no tie cases, standard rank and dense rank both will be same
// the first argument is the pointer to the first element of the recorded array
// the second argument is the size of the array
// the third argument is the pointer to the first element of the array where the corresponding ranks will be stored

int main()
{
    // STEP 1 ::: TAKING INPUT FROM THE USER, INPUT CAN ALSO BE TAKEN FROM A SOURCE FILE
    int n;
    printf("\nEnter the common number of observations of both the characteristics = ");
    scanf("%d", &n);

    int observation_set_1[n], observation_set_2[n];

    printf("\nEnter the observations regarding the first observation:::\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter observation_set_1 value_[%d] = ", i+1);
        scanf("%d", &observation_set_1[i]);
    }
    printf("\nEnter the observations regarding the second observation:::\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter observation_set_2 value_[%d] = ", i+1);
        scanf("%d", &observation_set_2[i]);
    }


    /* FILE* pointer2 = NULL;
    pointer2 = fopen("112_source.dat", "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(pointer2,"%d", &observation_set_1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        fscanf(pointer2,"%d", &observation_set_2[i]);
    }
    fclose(pointer2); */
    
    // STEP 2 ::: EVALUATING THE RANKS OF THE TWO SETS OF OBSERVATIONS
    int observation_set_1_rank[n];
    standard_rank(observation_set_1, n, observation_set_1_rank);

    int observation_set_2_rank[n];
    standard_rank(observation_set_2, n, observation_set_2_rank);

    // STEP 3 ::: CALCULATING THE DIFFERENCE BETWEEN THE CORRESPONDING RANKS
    int difference_in_rank[n];
    for (int i = 0; i < n; i++)
    {
        difference_in_rank[i] = observation_set_1_rank[i] - observation_set_2_rank[i];
    }

    // STEP 4 ::: CALCULATING THE SQUARE OF THE DIFFERENCES AND TOTAL OF THE SQUARES OF DIFFERENCES
    int square_difference[n], total_difference_square = 0;
    for (int i = 0; i < n; i++)
    {
        square_difference[i] = difference_in_rank[i] * difference_in_rank[i];
        total_difference_square = total_difference_square + square_difference[i];
    }

    // STEP 5 ::: CALCULATING SPEARMAN RANK CORRELATION COEFFICIENT
    float spearman_rank_correlation_coefficient;
    spearman_rank_correlation_coefficient = 1 - ( (6*(float)total_difference_square) / ( (float)(n*n*n) - (float)(n)) );

    // STEP 6 ::: DISPLAYING ALL THE CALCULATIONS IN THE TERMINAL
    printf("\nNECESSARY CALCULATION FOR SPEARMAN'S RANK CORRELATION COEFFICIENT\n");
    printf("-----------------------------------------------------------------\n");
    printf("\n\tSet_1 \t \t Rank_set_1 \t \t Set_2 \t \t Rank_set_2 \t \t difference_in_rank \t \t square_difference\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < n; i++)
    {
        printf("\n\t%5d \t \t %10d \t \t %5d \t \t %10d \t \t %18d \t \t \t %10d\n", observation_set_1[i], observation_set_1_rank[i], observation_set_2[i], observation_set_2_rank[i], difference_in_rank[i], square_difference[i]);
    }
    
    printf("\nThe Spareman's Rank Correlation Coefficient is %f", spearman_rank_correlation_coefficient);

    // STEP 7 ::: WRITING ALL THE CALCULATIONS IN AN OUTPUT FILE
    FILE* pointer = NULL;
    pointer = fopen("spearman_rank_21_124.dat", "w");

    fprintf(pointer,"NECESSARY CALCULATION FOR SPEARMAN'S RANK CORRELATION COEFFICIENT\n");
    fprintf(pointer,"-----------------------------------------------------------------\n");
    fprintf(pointer,"\nSet_1 \t \t Rank_set_1 \t \t Set_2 \t \t Rank_set_2 \t \t difference_in_rank \t \t square_difference\n");
    fprintf(pointer,"-----------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < n; i++)
    {
        fprintf(pointer,"\n%5d \t \t %10d \t \t %5d \t \t %10d \t \t %18d \t \t \t %10d\n", observation_set_1[i], observation_set_1_rank[i], observation_set_2[i], observation_set_2_rank[i], difference_in_rank[i], square_difference[i]);
    }
    
    fprintf(pointer,"\nThe Spearman's Rank Correlation Coefficient is %f", spearman_rank_correlation_coefficient);
    
    fclose(pointer);
    
    
    return 0;
}

void standard_rank(int* A, int a, int* B)
{
    for (int i = 0; i < a; i++)
    {
        int count = 0;
        for (int j = 0; j < a; j++)
        {
            if (*(A+i) < *(A+j))
            {
                count++;
            }
        }
        *(B+i) = count + 1;
    }
}