#include<stdio.h>

#include<stdlib.h>

int main(){
    FILE *pointer = NULL;
    pointer = fopen("data.dat", "r");
    char A[10];
    fscanf(pointer, "%c", &A[5]);
    printf("%c", A[5]);
    fclose(pointer);

    return 0;
}