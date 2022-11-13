#include<stdio.h>

int main()
{
    int testcases;
    scanf("%d", &testcases);

    int output_row[testcases], output_column[testcases];

    for (int i = 0; i < testcases; i++)
    {
        int row, column;
        scanf("%d", &row);
        scanf("%d", &column);

        if (row == 1 || column == 1) // then all the cells are isolated
        {
            output_row[i] = 1;
            output_column[i] = 1;
            continue;
        }
        else if (row == 2 && column == 2) // then all the cells are isolated
        {
            output_row[i] = 1;
            output_column[i] = 1;
            continue;
        }
        else if ( (row == 2 && column == 3) || (row == 3 && column == 2) || (row == 3 && column == 3) )
        {
            output_row[i] = 2;
            output_column[i] = 2;
            continue;
        }
        else
        {
            output_row[i] = 1;
            output_column[i] = 1;
        }
    }

    for (int i = 0; i < testcases; i++)
    {
        printf("%d %d\n", output_row[i], output_column[i]);
    }
    
    
    return 0;
}

// https://codeforces.com/problemset/problem/1739/A

/* 
if row = 1 or column = 1, all the cells are isolated. then printing any one of them is correct answer. I am printing (1,1)
if row = 2 and column = 2, i.e. for a 2X2 chessboard, all the cells are isolated. then printing any one of them is correct answer. I am printing (1,1)
for a 2X3 chessboard, cells (1,2) and (2,2) are isolated.
for a 3X2 chessboard, cells (2,1) and (2,2) are isolated.
for a 3X3 chessboard, cell (2,2) is isolated.
for any of the rest measurements, no cell is isolated. then printing any one of them is correct answer. I am printing (1,1)
if the knight can move two cells in any one of the directions, then the cell is not isolated. in that case it is also guranteed that the third cell to where the knight will take the perpendicular step is always available.
*/