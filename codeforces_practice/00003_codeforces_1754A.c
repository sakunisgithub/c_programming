#include<stdio.h>

int main()
{
    int testcases;
    scanf("%d", &testcases); // taking the input of number of testcases

    int number_of_messages[testcases];

    int result[testcases];

    for (int i = 0; i < testcases; i++)
    {
        scanf("%d", &number_of_messages[i]); // taking the input of the number of messages of the testcases

        char array[number_of_messages[i] + 1]; // as strings require to have a null character at the end

        scanf("%s", array); // taking input of the sequence of Q and A

        result[i] = 0;

        for (int j = 0; j < number_of_messages[i]; j++)
        {
            if (*(array+j) == 'Q')
            {
                result[i]++;
            }
            else if (*(array+j) == 'A' && result[i] > 0)
            {
                result[i]--;
            }

        }

    }

    for (int i = 0; i < testcases; i++)
    {
        if (result[i] == 0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }

    }
    
    return 0;
}

// https://codeforces.com/problemset/problem/1754/A
/* 
if there is a question, we add 1 to the result
if there is an answer and the we have due questions(i.e., the result is positive) we deduct 1 from the result
at last if all the questions are answered the result must be 0
*/