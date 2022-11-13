#include<stdio.h>

#include<stdlib.h>

int main(){
    FILE *pointer;
    pointer = fopen("data_file.dat", "w");
    fprintf(pointer,"Hi this is me, ananda from surendranath college");
    fclose(pointer);
    return 0;
}