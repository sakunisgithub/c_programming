#include<stdio.h>

int main()
{
    int A[3][3] = {1,2,3,4,5,6,7,8,9};
    int *p;
    // p = A; this is not valid
    p = &A[0][0];
    printf("%d\n", p);
    p = A[0];
    printf("%d\n", p);
    printf("%d\n", A);
    printf("%d\n", &A);
    printf("%d\n", *A);
    printf("%d\n", A[0]);
    printf("%d\n", A+1);
    printf("%d\n", *(A+1));
    printf("%d\n", *(A+1)+2);
    printf("%d\n", *(*(A+1)+2));
    printf("%d\n", *(A[1]+2));
    printf("%d\n", *(*A+1));
    printf("%d\n", **A);
    printf("%d\n", A[0]+1);
    printf("%d\n", &A[0]+1);


    return 0;
}