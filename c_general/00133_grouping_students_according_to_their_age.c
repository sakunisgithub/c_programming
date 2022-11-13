#include<stdio.h>

/* 
Accept the age of n students, find out how many of them are: a) <18, b) 18-25, c) >25
 */

int main()
{
    int n;
    printf("\nEnter the number of students = ");
    scanf("%d", &n);

    int age[n];

    printf("\nEnter the ages of the students ::: \n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter age of student[%d] = ", i+1);
        scanf("%d", &age[i]);
    }

    int less_18 = 0, between_18_25 = 0, greater_25 = 0;

    for (int i = 0; i < n; i++)
    {
        if (age[i] < 18)
        {
            less_18++;        
        }
        if (age[i] >= 18 && age[i] <= 25)
        {
            between_18_25++;
        }
        else if (age[i] > 25)
        {
            greater_25++;
        }
    }
    
    printf("\nAmong %d students,\n", n);
    printf("\n%d is/are below 18\n", less_18);
    printf("\n%d is/are between 18 and 25\n", between_18_25);
    printf("\n%d is/are above 25\n", greater_25);
    return 0;
}