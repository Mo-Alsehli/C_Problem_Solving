/*
-- Description:
In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

LeetCode: https://leetcode.com/problems/reshape-the-matrix/description/

-- Solution:
# Approach
- First we have to be sure that the reshape operation is possible.
- We allocate the right memory for all rows, columns and return columns size.
- Then we iterative over all elments and assign reshaped values.
```
reshapedMatrix[i / c][i % c] = mat[i / (*matColSize)][i % (*matColSize)];
```
- This formula iterate through 2d array without the need of two loops.


# Complexity
- Time complexity: O(m×n), where 𝑚 and 𝑛 are the number of rows and columns of the original matrix.

- Space complexity: O(r * c)

*/

#include <stdio.h>
#include <stdlib.h>

int **matrixReshape(int **mat, int matSize, int *matColSize, int r, int c, int *returnSize, int **returnColumnSizes)
{

    int totalElements = matSize * (*matColSize);
    int i;

    if (totalElements != (r * c))
    {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;

        return mat;
    }

    int **res = (int **)malloc(sizeof(int *) * r);
    *returnColumnSizes = (int *)malloc(sizeof(int) * r);

    for (i = 0; i < r; i++)
    {
        res[i] = (int *)malloc(sizeof(int) * c);
        (*returnColumnSizes)[i] = c;
    }

    for (i = 0; i < totalElements; i++)
    {
        res[i / c][i % c] = mat[i / (*matColSize)][i % (*matColSize)];
    }

    *returnSize = r;

    return res;
}

// Helper function to print the matrix
void printMatrix(int **matrix, int rows, int *colSizes)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colSizes[i]; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Example usage
    int mat[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    int *matPtrs[2] = {mat[0], mat[1]};
    int matColSize = 3;
    int r = 3;
    int c = 2;
    int returnSize;
    int *returnColumnSizes;

    int **reshapedMatrix = matrixReshape(matPtrs, 2, &matColSize, r, c, &returnSize, &returnColumnSizes);

    printf("Reshaped Matrix:\n");
    printMatrix(reshapedMatrix, returnSize, returnColumnSizes);

    // Free allocated memory
    for (int i = 0; i < returnSize; i++)
    {
        free(reshapedMatrix[i]);
    }
    free(reshapedMatrix);
    free(returnColumnSizes);

    return 0;
}