#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    
    int a,b,c;
    float d, r1, r2, p, q;

    printf("Enter An Integer Value for a\n");
    scanf("%d", &a);

    printf("Enter An Integer Value for b\n");
    scanf("%d", &b);

    printf("Enter An Integer Value for c\n");
    scanf("%d", &c);

    d= (b*b)-(4*a*c);

    if (d>0)
    {
        printf("The roots are real.\n");
        d=sqrt(d);
        r1= (-b+d)/(2.0*a);
        r2= (-b-d)/(2.0*a);
        printf("They are %f & %f", r1, r2);
    }

    else if (d==0)
    {
        printf("The roots are equal.\n");
        r1=(-b)/(2*a);
        printf("They are  %f & %f", r1, r1);
    }

    else if (d<0)
    {
        printf("The roots are complex.\n");
        d=sqrt(-d);
        p = (-b)/(2.0*a);
        q = (d)/(2.0*a);
        printf("They are %f+i%f and %f-i%f", p, q, p, q);
    }
    
    return 0;
}