#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define for(variable, initial_value, maximum_value) for(variable = initial_value; variable < maximum_value; variable++)

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetboard();
void printboard();
int checkfreespaces();
void playermove();
void computermove();
char checkwinner();
void printwinner(char);

int main()
{
    char winner = ' ';
    char response = ' ';

    do
    {
        
    
        printf("\n\nWELCOME !!");
        printf("\n\nThe COMPUTER is assigned 'O'\n");
        printf("\n\nThe USER is assigned 'X'\n");
        printf("\n\nAt first it is the user's turn and then the computer's turn\n");
        printf("\n\n\n");

        resetboard();

        winner = ' ';
        response = ' ';

        while (winner == ' ' && checkfreespaces() != 0)
        {
            printboard();

            playermove();
            winner = checkwinner();
            if (winner != ' ' || checkfreespaces() == 0)
            {
                break;
            }

            computermove();
            winner = checkwinner();
            if (winner != ' ' || checkfreespaces() == 0)
            {
                break;
            }

        }

        printboard();
        printwinner(winner);

        printf("\n\nWould you like to play again ? (Y/N) : ");
        getchar();
        scanf("%c", &response);
    
    } while (response == 'Y' || response == 'y');

    printf("\n\nThanks for playing !! \n");
    return 0;
}


void resetboard()
{
    int i, j;
    for(i, 0, 3)
    {
        for(j, 0, 3)
        {
            board[i][j] = ' ';
        }
    }
}


void printboard()
{
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n");

}


int checkfreespaces()
{
    int i, j, freespaces = 9;
    for(i, 0, 3)
    {
        for(j, 0, 3)
        {
            if (board[i][j] != ' ')
            {
                freespaces--;
            }
        }
    }
    
    return freespaces;
}


void playermove()
{
    printf("\n\nPLAYER'S MOVE");
    int x, y;
    input_again :
    printf("\nEnter the row number (1-3) = ");
    scanf("%d", &x);
    x--;
    printf("\nEnter the column number (1-3) = ");
    scanf("%d", &y);
    y--;

    if (board[x][y] != ' ')
    {
        printf("\nOops !! Invalid Input !!");
        printf("\nInput again !!");
        goto input_again;
    }
    else
    {
        board[x][y] = PLAYER;
    }
}


void computermove()
{
    srand(time(NULL));
    
    int x, y;
    
    /* if (checkfreespaces() > 0)
    { */
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
        
    /* }
    else
    {
        printwinner(' ');
    } */
}


char checkwinner()
{
    int i, j, code;

    // checking row wise winning possibilites
    for(i, 0, 3)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
        {
            code = 1;
            return board[i][0];
        }
    }

    // checking column wise winning possibilites
    for(i, 0, 3)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
        {
            code = 2;
            return board[0][i];
        }
    }

    // checking the principal diagonal wise winning possibilites
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
    {
        code = 3;
        return board[0][0];
    }

    // checking the other diagonal wise winning possibilites
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
    {
        code = 4;
        return board[2][0];
    }

    return ' ';
}


void printwinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("\n\nYou WIN !! Congrats !!");
    }
    if (winner == COMPUTER)
    {
        printf("\n\nThe computer wins !!");
    }
    if (winner == ' ')
    {
        printf("\n\nGame Drawn !!");
    }
}