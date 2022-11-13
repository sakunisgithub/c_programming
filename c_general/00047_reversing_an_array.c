#include<stdio.h>
//reversing an array using functions
void display(int*, int);

void reverse_array(int*, int);

void swap(int*, int*);

int main(){
    int n;
    printf("Enter your array length n = ");
    scanf("%d", &n);

    int array[n];
    int i;
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter array[%d] = ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\n");
    
    printf("The initial array is\n");
    display(array, n);

    reverse_array(array, n);

    printf("\n");

    printf("The final array is\n");
    display(array, n);

   
    return 0;
}

void display(int* pointer, int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("%d  ", *(pointer+i));
    }
    
}

void reverse_array(int* pointer, int a)
{
    for (int i = 0; i < a/2; i++)
    {
        swap(  (pointer+i) , (pointer+(a-1)-i)  );
    }
    
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}