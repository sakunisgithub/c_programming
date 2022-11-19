#include<stdio.h>

int main()
{
    int testcases;
    // printf("\nEnter the number of testcases = ");
    scanf("%d", &testcases);

    int output[testcases];
    int number_of_digits_absent[testcases];
    int digits_present[testcases];

    for (int i = 0; i < testcases; i++)
    {
        // printf("\nEnter the number of digits that Monocrap remembers that they were not present in the password = ");
        scanf("%d", &number_of_digits_absent[i]);

        int digits;
        // printf("\nEnter the absent digits in the ascending order :: \n");

        for (int j = 0; j < number_of_digits_absent[i]; j++)
        {
            scanf("%d", &digits); // just scanning the digits(because the question says to have the absent digits as input), not storing them(to not use unnecessary memory) as we don't need them to calculate the number of possible 4 digit numbers
        }
    }

    // Given that, Monocrap's password has 2 distinct digits, each appering twice
    // Let the digits be a, b. Then number of possible 4 digit numbers out of them is 4!/(2!2!) = 6
    // Now, number of ways to choose two digits from the digits_present is (digits_present)C(2) 
    // i.e. (digits_present X (digits_present - 1)) / 2
    // So, number of possible 4 digit numbers is 6 * ((digits_present X (digits_present - 1)) / 2)

    for (int i = 0; i < testcases; i++)
    {
        digits_present[i] = 10 - number_of_digits_absent[i];
        output[i] = 6 * ( (digits_present[i] * (digits_present[i] - 1)) / 2 ) ;
        printf("%d\n", output[i]);
        
    }
    
    return 0;
}

// https://codeforces.com/problemset/problem/1743/A