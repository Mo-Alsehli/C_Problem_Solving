/*
-- Description:

Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor.

The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.
Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

Example 1:
Input: candyType = [1,1,2,2,3,3]
Output: 3
Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.

LeetCode: https://leetcode.com/problems/distribute-candies/description/

-- Solution:
# Approach
- Make array of 20001 element and init them with 0.
- Make a 100000 offset to handle Negative numbers.
- You loop through each candy type in the candyType array.
For each candy, you check if it has already been seen using the type array. If not, you mark it as seen and increment the currType counter.
- If currType reaches maxTypes (which is half the size of the candyType array), you return maxTypes immediately. This ensures that Alice can eat the maximum number of different types of candies.
- If the loop completes without reaching maxTypes, you return the number of unique types (currType).

# Complexity
- Time complexity: O(n)
- Space complexity: O(1)
 */

#include <stdio.h>

int distributeCandies(int *candyType, int candyTypeSize)
{
    int type[200001] = {0};
    int offset = 100000;
    int i;
    int maxTypes = candyTypeSize / 2;
    int currType = 0;

    for (i = 0; i < candyTypeSize; i++)
    {
        if (type[candyType[i] + offset] == 0)
        {
            type[candyType[i] + offset] = 1;
            currType++;
        }

        if (currType == maxTypes)
        {
            return maxTypes;
        }
    }

    return currType;
}

int main()
{
    int candyType1[] = {1, 1, 2, 2, 3, 3};
    int candyTypeSize1 = sizeof(candyType1) / sizeof(candyType1[0]);
    printf("Example 1: %d\n", distributeCandies(candyType1, candyTypeSize1)); // Output: 3

    int candyType2[] = {1, 1, 2, 3};
    int candyTypeSize2 = sizeof(candyType2) / sizeof(candyType2[0]);
    printf("Example 2: %d\n", distributeCandies(candyType2, candyTypeSize2)); // Output: 2

    int candyType3[] = {6, 6, 6, 6};
    int candyTypeSize3 = sizeof(candyType3) / sizeof(candyType3[0]);
    printf("Example 3: %d\n", distributeCandies(candyType3, candyTypeSize3)); // Output: 1

    return 0;
}