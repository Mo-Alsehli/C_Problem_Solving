/*
-- Description:
- You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.
- Count and return the number of maximum integers in the matrix after performing all the operations.

Example 1:
Input: m = 3, n = 3, ops = [[2,2],[3,3]]
Output: 4
Explanation: The maximum integer in M is 2, and there are four of it in M. So return 4.

Example 2:
Input: m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
Output: 4

LeetCode: https://leetcode.com/problems/range-addition-ii/description/

-- Solution
- Get the minimum value of n and m operations and this is our solution.
- Bigger values of operations must contain smaller ones but smaller values don't contain bigger ones.

-- Complexity
Time complexity: O(n)
Space complexity: O(1)
 */

#include <stdio.h>

int maxCount(int m, int n, int **ops, int opsSize, int *opsColSize)
{

    int minM = m;
    int minN = n;

    for (int i = 0; i < opsSize; i++)
    {
        if (ops[i][0] < minM)
        {
            minM = ops[i][0];
        }

        if (ops[i][1] < minN)
        {
            minN = ops[i][1];
        }
    }

    return minM * minN;
}

int main()
{
    int m = 3, n = 3;
    int opsSize = 3;
    int opsColSize[] = {2, 2, 2};
    int ops[3][2] = {
        {2, 2},
        {3, 3},
        {3, 3}};

    int *opsPtrs[3] = {ops[0], ops[1], ops[2]};

    int result = maxCount(m, n, opsPtrs, opsSize, opsColSize);
    printf("The number of maximum integers in the matrix is: %d\n", result); // Output: 4

    return 0;
}