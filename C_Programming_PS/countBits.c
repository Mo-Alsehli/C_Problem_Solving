#include <stdio.h>
#include <stdlib.h>

/*
Description:
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Leetcode: https://leetcode.com/problems/counting-bits/description/

Solution:
In this code, the countSetBits function calculates the count of set bits in a number using a while loop and bitwise operations.

The countBits function creates an array of size n + 1 and populates it with the count of set bits for each number from 0 to n.
*/

// Function to calculate the count of set bits in a number
int countSetBits(int num)
{
    int count = 0;
    while (num > 0)
    {
        count += num & 1; // Check if LSB is set
        num >>= 1;        // Shift right by one place
    }
    return count;
}

int *countBits(int n, int *returnSize)
{
    *returnSize = n + 1;
    int *ans = (int *)malloc((*returnSize) * sizeof(int));

    for (int i = 0; i <= n; i++)
    {
        ans[i] = countSetBits(i);
    }

    return ans;
}

int main()
{
    int n = 2;
    int returnSize;

    int *result = countBits(n, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d", result[i]);
        if (i < returnSize - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");

    // Free the dynamically allocated memory
    free(result);

    return 0;
}
