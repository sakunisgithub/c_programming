#include<stdio.h>

#include<stdlib.h>

int main(){
    int n;
    float obs, freq;

    FILE *pointer = NULL;
    pointer = fopen("00052_storing_data.dat", "w");

    printf("Enter total number of observations\n");
    scanf("%d", &n);

    fprintf(pointer, "Values   \t Frequencies\n");

    for (int i = 0; i < n; i++)
    {
        printf("Enter observation : \n");
        scanf("%f", &obs);

        printf("Enter frequency : \n");
        scanf("%f", &freq);

        fprintf(pointer, "%f\t %f\n", obs, freq);
    }

    fclose(pointer);

    return 0;
}