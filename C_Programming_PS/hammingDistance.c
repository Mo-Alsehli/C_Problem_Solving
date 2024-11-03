/*
-- Description:
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, return the Hamming distance between them.

Example 1:
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.

-- Solution:
We create a function that takes a number and a position and return the value of corresponding position bit then we compare the outputs for the two numbers.

-- LeetCode: https://leetcode.com/problems/hamming-distance

-- Time Complexity : O(1).
-- Space Complexity: O(1).
 */

#include <stdio.h>

int isBitSet(int num, int pos)
{
    // Shift 1 to the left by 'pos' to create the bitmask
    int bitmask = 1 << pos;

    // Perform bitwise AND between 'num' and the bitmask
    // If the result is non-zero, the bit at 'pos' is set
    if ((num & bitmask) != 0)
    {
        return 1; // Bit is set
    }
    else
    {
        return 0; // Bit is not set
    }
}

int hammingDistance(int x, int y)
{
    int i, distance = 0;

    for (i = 0; i < 31; i++)
    {
        if ((int)isBitSet(x, i) != (int)isBitSet(y, i))
        {
            distance++;
        }
    }

    return distance;
}

int main()
{
    int x = 1, y = 4;
    printf("Hamming distance between %d and %d: %d\n", x, y, hammingDistance(x, y));
    return 0;
}