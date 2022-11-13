#include<stdio.h>

//multiplication table of 2, 7, 9

int main(){

    int array[3][10];
    int num[] = {2,7,9};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            array[i][j] = num[i]*(j+1);
            printf("%d\t", array[i][j]);
        }
        printf("\n");
        
    }
    
    return 0;
}