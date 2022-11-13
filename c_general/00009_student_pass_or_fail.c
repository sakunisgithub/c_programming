#include<stdio.h>

int main(){
    
    // We assume that full marks in each subject is 100. 
    // Thus passing marks in each subject is 33 and total required marks to pass is 120
    int a,b,c,p,t;

    printf("Enter the marks of subject 1\n");
    scanf("%d", &a);

    printf("Enter the marks of subject 2\n");
    scanf("%d", &b);

    printf("Enter the marks of subject 3\n");
    scanf("%d", &c);
    
    p=(300*40)/100;
    t= a+b+c;
    
    if (a>=33 && b>=33 && c>=33 && t>=p)
    {
        printf("The student has passed.");
    }
    else
    {
        if (a<33)
        {
            printf("The student has failed because he/she could not secure the passing marks in subject 1.\n");
        }
        if (b<33)
        {
            printf("The student has failed because he/she could not secure the passing marks in subject 2.\n");
        }
        if (c<33)
        {
            printf("The student has failed because he/she could not secure the passing marks in subject 3.\n");
        }
        if (t<p)
        {
            printf("The student has failed because he/she could not secure the total passing marks.");
        }
    }
 
    return 0;
}