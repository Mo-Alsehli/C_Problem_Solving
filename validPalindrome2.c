/*
-- Description:
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:
Input: s = "aba"
Output: true

Example 2:
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Example 3:
Input: s = "abc"
Output: false

LeetCode: https://leetcode.com/problems/valid-palindrome-ii/description/

-- Solution:
# Approach
- Make a function to check if it's a `Palindrome` using two pointers approach.
- Check for the edge cases and check if the word is palindrome.
- If it's not palindrome check for unequal characters and skip one at a time then check if the rest is a palindrome.

# Complexity
- Time complexity: O(n)
- Space complexity: O(1)

 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Helper function to check if a substring is a palindrome
bool isPalindrome(char *s, int left, int right)
{
    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool validPalindrome(char *s)
{
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            // Check both possibilities: skipping left or skipping right
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
    }

    return true;
}

int main()
{
    char s1[] = "aba";
    char s2[] = "abca";
    char s3[] = "abc";

    printf("Test case 1: %s\n", validPalindrome(s1) ? "true" : "false"); // Expected: true
    printf("Test case 2: %s\n", validPalindrome(s2) ? "true" : "false"); // Expected: true
    printf("Test case 3: %s\n", validPalindrome(s3) ? "true" : "false"); // Expected: false

    return 0;
}
