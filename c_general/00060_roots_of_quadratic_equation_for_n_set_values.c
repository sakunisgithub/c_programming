#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// The program will automatically create a source file named source_file_60.dat and an output file named results_60.dat


int main(){
    int n;
    printf("Enter total number of sets of values you want to enter : \n");
    scanf("%d", &n);

    int a, b, c;
    float d, r1, r2, p, q;

    FILE *pointer1 = NULL;
    pointer1 = fopen("source_file_60.dat", "w");
    
    for (int i = 1; i <= n; i++)
    {
        printf("\nSet No. %d : Enter an integer for a = ", i);
        scanf("%d", &a);
        fflush(stdin);
        fprintf(pointer1, "%d\t", a);

        printf("\nSet No. %d : Enter an integer for b = ", i);
        scanf("%d", &b);
        fflush(stdin);
        fprintf(pointer1, "%d\t", b);

        printf("\nSet No. %d : Enter an integer for c = ", i);
        scanf("%d", &c);
        fprintf(pointer1, "%d\n", c);
        fflush(stdin);
    }
    fclose(pointer1);

    pointer1 = fopen("source_file_60.dat", "r");

    FILE *pointer2 = NULL;
    pointer2 = fopen("results_60.dat", "w");

    fprintf(pointer2, "Values of a \t Values of b \t Values of c\n");

    for (int i = 1; i <= n; i++)
    {
        fscanf(pointer1, "%d", &a);
        fscanf(pointer1, "%d", &b);
        fscanf(pointer1, "%d", &c);

        d= (b*b)-(4*a*c);

        fprintf(pointer2, "%d                %d                %d\nRemarks :: ", a, b, c);


        if (d>0)
        {
            d=sqrt(d);
            r1= (-b+d)/(2.0*a);
            r2= (-b-d)/(2.0*a);
            fprintf(pointer2, "The roots are real and they are %f & %f\n", r1, r2);
        }

        else if (d==0)
        {
            r1=(-b)/(2*a);
            fprintf(pointer2, "The roots are real and equal. They are  %f & %f\n", r1, r1);
        }   

        else if (d<0)
        {
            d=sqrt(-d);
            p = (-b)/(2.0*a);
            q = (d)/(2.0*a);
            fprintf(pointer2, "The roots are imaginary. They are %f+i%f and %f-i%f\n", p, q, p, q);
        }

    }

    fclose(pointer1);
    fclose(pointer2);
 
    return 0;
}