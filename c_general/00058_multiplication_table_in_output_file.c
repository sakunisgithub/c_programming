#include<stdio.h>

#include<stdlib.h>

int main(){
    int n;
    printf("Enter your number\n");
    scanf("%d", &n);
    FILE *pointer = NULL;
    pointer = fopen("Multiplication_table.dat", "a");
    for (int i = 1; i <= 10; i++)
    {
        fprintf(pointer, "%d x %d = %d\n", n, i, n*i);
    }
    fclose(pointer);
    
    return 0;
}