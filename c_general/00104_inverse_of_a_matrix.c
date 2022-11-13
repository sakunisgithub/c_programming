#include <stdio.h>

// this program will calculate inverse of non-singular matrices only.
// we can always add the program to find the determinant here, attach an if-else condition and if the value of the determinant becomes 0, we will terminate the program saying that the matrix is not invertible.

/* We have used elementary row operations to find out the inverse of the given matrix.
We shall perform certain row operations on the given matrix in order to make it an identity matrix of that order.
On the same time we shall also perform the same row operations on the operand identity matrix whose order is same as that of the inputed matrix.
At the end, the derived form of the operand matrix will be our required inverse matrix.
The various steps of this program are as follows along with their line numbers::
step 1 : input (29-46)
        we are inputting the order of the square matrix and then we are inputting the entries of the matrix row-wise one by one
step 2 : printing the recorded matrix (48-58)
step 3 : creating and printing the required operand matrix (60-90) The printing part has been commented out.
step 4 : performing the first kind of row operations on both the matrices (91-108)
step 5 : after row operations of kind one, printing the current form of the input matrix (110-125) This part has been commented out.
step 6 : performing the second kind of row operations on both the matrices (127-147)
step 7 : printing the required inverse matrix (161-171)

First Kind of operation ::: here, we are going column-wise. Except the diagonal entry of that particular column, we are converting every other entry of the column to 0(zero).
                            And whatever we are doing on the input matrix, we are doing the same operations on the operand identity matrix.
Second Kind of operation ::: here, we have all the entries of the input matrix as 0 except the diagonal ones.
                            If any of these diagonal elements is not equal to 1, we are dividing that row by reciprocal of that diagonal element to make the diagonal element 1.
                            As all other entries of that row are already 0, we are not having any side-effect.
                            And whatever we are doing on the input matrix, we are doing the same operations on the operand identity matrix. */

int main()
{
    int row;
    printf("\nEnter the order of the square matrix = ");
    scanf("%d", &row);

    printf("\nEnter the matrix :: \n");

    float matrix[row][row]; // the input matrix

    // inputting the matrix

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("\nEnter matrix[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    // printing the recorded matrix

    printf("\nThe recorded matrix is ::: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }

    // creating the operand identity matrix

    float identity[row][row]; // the operand matrix

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (i == j)
            {
                identity[i][j] = 1;
            }
            else
            {
                identity[i][j] = 0;
            }
        }
    }

    // printing the operand identity matrix

    /* printf("\nThe operand identity matrix is ::: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%f\t", identity[i][j]);
        }
        printf("\n");
    } */

    // performing operations of the first kind

    for (int c = 0; c < row; c++) // going column-wise
    {
        for (int r = 0; r < row; r++) // accessing the rows
        {
            if (r != c) // making all the non-diagonal elements of the inputed matrix 0(zero)
            {
                float ratio = matrix[r][c] / matrix[c][c];
                for (int i = 0; i < row; i++)
                {
                    matrix[r][i] = matrix[r][i] - (ratio * matrix[c][i]); // doing operations on the recorded matrix

                    identity[r][i] = identity[r][i] - (ratio * identity[c][i]); // doing the same operations on the operand identity matrix
                }
            }
        }
    }

    // printing the sigma matrix

    // sigma matrix is such a matrix that has all the non-diagonal elements 0(zero)

    /* printf("\nsigma matrix is such a matrix that has all the non-diagonal elements 0(zero).\n");

    printf("\nThe sigma matrix is ::: \n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    } */

    // transforming the sigma matrix to its identity form i.e. performing operations of the second kind

    for (int i = 0; i < row; i++)
    {
        if (matrix[i][i] != 1)
        {
            for (int j = 0; j < row; j++)
            {
                identity[i][j] = identity[i][j] / matrix[i][i]; // if any of the diagonal elements of the operand identity matrix becomes 0, then this calculation will fail.
            }
            for (int j = 0; j < row; j++)
            {
                matrix[i][j] = matrix[i][j] / matrix[i][i]; // if any of the diagonal elements of the sigma matrix becomes 0, then this calculation will fail.
            }
            // there is certain reason why I have done this operation on the operand matrix first and then I have done the operation on the input matrix.
            // If you do this operation on the input matrix first and then do it on the operand matrix, you will have incorrect inverse matrix output.
            // why??? because if you perform the operation on the input matrix first, all the diagonal entries that are not 1, will be converted to 1.
            // and then if you divide the entries of the operand identity matrix by the diagonal entires of the input matrix, you are basically dividing them by 1.
            // so you will get incorrect inverse matrix output.
        }
    }

    // printing the sigma cum identity matrix

    // printf("\nThe sigma cum identity matrix is ::: \n");
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < row; j++)
    //     {
    //         printf("%f\t", matrix[i][j]);
    //     }
    //     printf("\n");
    // }

    // printing the operand identity matrix which has become the required inverse matrix

    printf("\nThe required inverse matrix is :::\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%f\t", identity[i][j]);
        }
        printf("\n");
    }

    return 0;
}