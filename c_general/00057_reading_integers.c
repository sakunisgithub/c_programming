#include<stdio.h>

#include<stdlib.h>

int main(){
    FILE *pointer ;
    pointer = fopen("data.dat", "r");
    int n;
    for (int i = 0; i < 3; i++)
    {
        fscanf(pointer, "%d", &n);
        printf("%d\n", n);
    }
    
    
    fclose(pointer);
    return 0;
}