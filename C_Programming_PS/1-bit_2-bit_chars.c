/*
-- Description:
We have two special characters:
The first character can be represented by one bit 0.
The second character can be represented by two bits (10 or 11).
Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.

Example 1:
Input: bits = [1,0,0]
Output: true
Explanation: The only way to decode it is two-bit character and one-bit character.
So the last character is one-bit character.

Example 2:
Input: bits = [1,1,1,0]
Output: false
Explanation: The only way to decode it is two-bit character and two-bit character.
So the last character is not one-bit character.

-- LeetCode: https://leetcode.com/problems/1-bit-and-2-bit-characters/description/

-- Solution:
# Approach
- If `bits[i]` is `0`, we increment `i` by `1`.
- After the loop, if `i` points to the last bit in the array, it means the last bit is a one-bit character `(0)`, so we return `true`.
- If the last bit was part of a two-bit character, `i` would have moved past the last element, and we return `false`.

# Complexity
- Time complexity: O(n)
- Space complexity: O(1)

 */

#include <stdio.h>
#include <stdbool.h>

bool isOneBitCharacter(int *bits, int bitsSize)
{
    int i = 0;

    // Iterate through the array
    while (i < bitsSize - 1)
    {
        if (bits[i] == 1)
        {
            i += 2; // Skip the next bit as it is part of a two-bit character
        }
        else
        {
            i += 1; // Move to the next bit
        }
    }

    // If we are at the last bit, then it's a one-bit character
    return i == bitsSize - 1;
}

int main()
{
    // Example 1
    int bits1[] = {1, 0, 0};
    int size1 = sizeof(bits1) / sizeof(bits1[0]);
    printf("Result for Example 1: %s\n", isOneBitCharacter(bits1, size1) ? "true" : "false");

    // Example 2
    int bits2[] = {1, 1, 1, 0};
    int size2 = sizeof(bits2) / sizeof(bits2[0]);
    printf("Result for Example 2: %s\n", isOneBitCharacter(bits2, size2) ? "false" : "true");

    return 0;
}
