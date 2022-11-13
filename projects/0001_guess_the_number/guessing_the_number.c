#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int number, guess, count=1, lower, upper, a, b;

int main(){

    printf("Enter Your Lower Limit\n");
    scanf("%d", &lower);

    printf("Enter Your Upper Limit\n");
    scanf("%d", &upper);

    a = upper-lower + 1;

    srand(time(NULL));
    b = rand()%a;
    number = b + lower ;
    // printf("%d",number);

    printf("Your Guess = ");
    scanf("%d", &guess);

    do
    {
        if (guess>number)
            {
            ++count;
            printf("Guess a smaller number.\t");
            printf("Attempt Number %d.\t", count);
            printf("Your Guess = ");
            scanf("%d", &guess);
            }
        else if (guess<number)
            {
            ++count;
            printf("Guess a larger number.\t");
            printf("Attempt Number %d.\t", count);
            printf("Your Guess = ");
            scanf("%d", &guess);
            }
    } while (guess!=number);

    if (guess==number)
        {
        printf("You got it.\n");
                if (count==1)
                {
                    printf("Well done champ!! You took %d attempt only.", count);
                }
                else if (count>=2)
                {
                    printf("Congratulations!!You took %d attempts.", count);
                }
        }

    return 0;
}