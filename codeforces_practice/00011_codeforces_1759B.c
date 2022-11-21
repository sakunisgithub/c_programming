#include<stdio.h>
#include<math.h>

int check_n(int, int);

int check_whole_square(int);

int main()
{
    int testcases;
    scanf("%d", &testcases);

    int output[testcases];

    for (int i = 0; i < testcases; i++)
    {
        int m, s;
        // m is the number of remembered numbers
        // s is the sum of the forgotten numbers

        scanf("%d", &m);
        scanf("%d", &s);

        int array[m];

        for (int i = 0; i < m; i++)
        {
            scanf("%d", &array[i]);
        }

        int sum = 0, x;
        // sum is the sum of the remembered numbers that are the bi's
        // x is the maximum of the remembered numbers that are the bi's

        x = array[0];
        sum = array[0];

        for (int i = 1; i < m; i++)
        {
            if (*(array + i) > x)
            {
                x = *(array + i);
            }

            sum += *(array + i);
        }

        int matured_sum = ( (x * (x + 1)) / 2 );
        // matured_sum is the sum of a valid permutation which is nothing but the sum of the first x natural numbers, x being the greatest natural number in the permutation

        if (matured_sum == sum) // then the given bi's are already a valid permutation
        {
            output[i] = check_n(x, s);
        }
        else if (matured_sum - sum > s)
        {
            output[i] = 0;
        }
        else if (matured_sum - sum == s)
        {
            output[i] = 1;
        }
        else if (matured_sum - sum < s)
        {
            int k = s - matured_sum + sum;
            output[i] = check_n(x, k);
        }

    }    

    for (int i = 0; i < testcases; i++)
    {
        if (output[i])
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    
    return 0;
}

int check_n(int p, int q)
{
    int b = 2*p + 1;
    int c = 0 - 2*q;

    if ((b*b - 4*c) == 0)
    {
        if (b % 2 == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if ((b*b - 4*c) > 0)
    {
        if ((b % 2 != 0) && check_whole_square(b*b - 4*c))
        {
            return 1; 
        }
        else
        {
            return 0;
        }
    }
    else if ((b*b - 4*c) < 0)
    {
        return 0;
    }
    
}

int check_whole_square(int discriminant)
{
    int temp = sqrt(discriminant);

    if (temp * temp == discriminant)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// https://codeforces.com/contest/1759/problem/B

// https://drive.google.com/file/d/1eT8xD47jWZnz71V5e31yBJ9AqrwSp9zm/view?usp=sharing