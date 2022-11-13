#include<stdio.h>
#include<time.h>
#include<stdlib.h>

// The user has to input r or s or p only. Otherwise the computer will gain 1 bonus point.

// If the user enters a word or any other thing that starts with r or s or p, the system by default will read the first letter as input and show results accordingly.


int rock_paper_scissor(char, char);

int main(){
    int number,result, n, score_user = 0, score_computer = 0;
    char user, computer;

    printf("Enter the number of rounds you want to play\n");
    scanf("%d", &n);
    fflush(stdin);

    for (int i = 1; i <= n; i++)
    {
        srand(time(NULL));
        number = rand()%100 + 1;

        if (number < 30)
        {
            computer = 'r';
        }
        else if (number < 65)
        {
            computer = 'p';
        }
        else
        {
            computer = 's';
        }

        printf("Enter 'r' for rock or 'p' for paper or 's' for scissor\n");
        scanf("%c", &user);
        fflush(stdin);

        printf("Round Number : %d \t Computer chose %c \t User chose %c \t", i, computer, user);
        

        result = rock_paper_scissor(user, computer);

        if (result == 0)
        {
            printf("Game Drawn.\n");
        }
        else if (result == 1)
        {
            score_user++;
            printf("User won.\n");
        }
        else if (result == 2)
        {
            score_computer++;
            printf("Computer won.\n");
        }
        else if (result == -1)
        {
            score_computer++;
            printf("Invalid Input by User!!! Computer is awarded 1 bonus point.\n");
        }
        
        if (i == n)
        {
            printf("Final Score => User vs Computer => %d : %d", score_user, score_computer);
        }
        
        
    }

    return 0;
}

int rock_paper_scissor(char A,char B)
    {
        if (A == B)
        {
            return 0;
        }
        else if (A == 'r' && B == 'p')
        {
            return 2;
        }
        else if (A == 'r' && B == 's')
        {
            return 1;
        }
        else if (A == 'p' && B == 'r')
        {
            return 1;
        }
        else if (A == 'p' && B == 's')
        {
            return 2;
        }
        else if (A == 's' && B == 'r')
        {
            return 2;
        }
        else if (A == 's' && B == 'p')
        {
            return 1;
        }
        else if (A != 'r' || A != 'p' || A != 's')
        {
            return -1;
        }
        
    }