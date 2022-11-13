#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// The program will automatically create a source file named source_file_61.dat and an output file named results_61.dat

int main(){

    int n;
    printf("Enter total number of classes : \n");
    scanf("%d", &n);

    float lower[n], upper[n], frequency[n], mark[n], product[n], deviation[n];
    float total_sum = 0, total_frequency = 0, total_deviation = 0, mean, variance, standard_deviation;

    FILE *pointer1 = NULL;
    pointer1 = fopen("source_file_61.dat", "w");

    for (int i = 1; i <= n; i++)
    {
        printf("\nClass No. %d : Enter Lower Class Boundary = ", i);
        scanf("%f", &lower[i]);
        fflush(stdin);
        fprintf(pointer1, "%f\t", lower[i]);

        printf("\nClass No. %d : Enter upper Class Boundary = ", i);
        scanf("%f", &upper[i]);
        fflush(stdin);
        fprintf(pointer1, "%f\t", upper[i]);

        printf("\nClass No. %d : Enter Class Frequency = ", i);
        scanf("%f", &frequency[i]);
        fflush(stdin);
        fprintf(pointer1, "%f\n", frequency[i]);
    }
    fclose(pointer1);

    pointer1 = fopen("source_file_61.dat", "r");

    FILE *pointer2 = NULL;
    pointer2 = fopen("results_61.dat", "w");

    fprintf(pointer2, "Lower Boundary     Upper Boundary     Frequency\n");

    for (int i = 1; i <= n; i++)
    {
        fscanf(pointer1, "%f", &lower[i]);
        fprintf(pointer2, "%f          ", lower[i]);

        fscanf(pointer1, "%f", &upper[i]);
        fprintf(pointer2, "%f          ", upper[i]);

        fscanf(pointer1, "%f", &frequency[i]);
        fprintf(pointer2, "%f\n", frequency[i]);

        mark[i] = ((lower[i] + upper[i])/2.0);

        product[i] = mark[i] * frequency[i];

        total_sum = total_sum + product[i];

        total_frequency = total_frequency + frequency[i];

    }

    mean = total_sum/total_frequency;

    fprintf(pointer2, "\nMean = %f", mean);

    for (int i = 1; i <= n; i++)
    {
        deviation[i] = (mark[i] - mean) * (mark[i] - mean) * frequency[i];

        total_deviation = total_deviation + deviation[i];
    }

    variance = total_deviation/total_frequency;

    fprintf(pointer2, "\nVariance = %f", variance);

    standard_deviation = sqrt(variance);

    fprintf(pointer2, "\nStandard Deviation = %f", standard_deviation);

    fprintf(pointer2, "\nCoefficient of Variation = %f", ((standard_deviation/mean)*100));

    fclose(pointer1);
    fclose(pointer2);
  
    return 0;
}