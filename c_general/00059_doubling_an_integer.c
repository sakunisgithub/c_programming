#include<stdio.h>

#include<stdlib.h>

int main(){
    int n;
    FILE *pointer = NULL;
    pointer = fopen("integer.dat", "r");
    fscanf(pointer, "%d", &n);
    fclose(pointer);
    pointer = fopen("integer.dat", "w");
    fprintf(pointer, "%d", n*2);
    fclose(pointer);
    return 0;
}