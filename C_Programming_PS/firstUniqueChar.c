#include <stdio.h>
#include <string.h>

/*
-- Description:
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Example 3:
Input: s = "aabb"
Output: -1

LeetCode: https://leetcode.com/problems/first-unique-character-in-a-string/description/

-- Solution:
you can solve this problem in C by iterating through the string and maintaining a frequency count of each character. Once you have the frequency count, you can then find the first character with a count of 1, which indicates a non-repeating character.
*/

int firstUniqChar(char *s)
{
    int char_count[26] = {0}; // Assuming lowercase English letters

    // Count characters in the string
    for (int i = 0; i < strlen(s); i++)
    {
        char_count[s[i] - 'a']++;
    }

    // Find the first non-repeating character
    for (int i = 0; i < strlen(s); i++)
    {
        if (char_count[s[i] - 'a'] == 1)
        {
            return i;
        }
    }

    return -1; // No non-repeating character found
}

int main()
{
    char s1[] = "leetcode";
    printf("%d\n", firstUniqChar(s1)); // Output: 0

    char s2[] = "loveleetcode";
    printf("%d\n", firstUniqChar(s2)); // Output: 2

    char s3[] = "aabb";
    printf("%d\n", firstUniqChar(s3)); // Output: -1

    return 0;
}
