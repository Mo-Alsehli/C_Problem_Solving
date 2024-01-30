/*
-- Description:
- Given a string s, return the number of segments in the string.
A segment is defined to be a contiguous sequence of non-space characters.

Example 1:
Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]

-- LeetCode: https://leetcode.com/problems/number-of-segments-in-a-string/description/

-- Solution:
To count the number of segments in a string, you can iterate through the characters of the string and check if a character is non-space and its previous character is a space or if it's the first character.

-- Time Complexity: O(n)
-- Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdbool.h>

int countSegments(char *s)
{
    int count = 0;
    bool inSegment = false;

    // Iterate through each character
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ')
        {
            // If the current character is non-space and the previous one is a space or it's the first character
            if (!inSegment)
            {
                count++; // Start of a new segment
                inSegment = true;
            }
        }
        else
        {
            // If the current character is a space
            inSegment = false; // Mark the end of the current segment
        }
    }

    return count;
}

int main()
{
    char str1[] = "Hello, my name is John";
    char str2[] = "Hello";

    printf("Number of segments in '%s': %d\n", str1, countSegments(str1));
    printf("Number of segments in '%s': %d\n", str2, countSegments(str2));

    return 0;
}
