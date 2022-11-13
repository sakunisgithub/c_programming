#include<stdio.h>

#include<stdlib.h>

int main(){
    int n;
    float x, y;
    FILE *pointer = NULL;
    pointer = fopen("52_storing_data.dat", "r");
    printf("Enter the number of observations you want to call\n");
    scanf("%d", &n);
    printf("Observation      Frequency\n");
    for (int i = 0; i < n; i++)
    {
        fscanf(pointer, "%f %f", &x, &y);
        printf("%f \t %f\n", x, y);
    }
    fclose(pointer);
    
    return 0;
}