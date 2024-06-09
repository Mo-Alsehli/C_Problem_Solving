/*
-- Descriptoin:
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:
Input: s = "Mr Ding"
Output: "rM gniD"

LeetCode: https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

-- Solution:
# Approach
<!-- Describe your approach to solving the problem. -->
- Implement Reverse Function To reverse Words.
- Loop through string until you find a space then reverse the word.

# Complexity
- Time complexity: O(n)
- Space complexity: O(1)
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void reverse(char *s, int start, int end)
{
    char temp = s[start];
    while (start < end)
    {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

char *reverseWords(char *s)
{
    int len = strlen(s);
    int i = 0, j = 0;
    for (i = 0; i < len; i++)
    {
        if (s[i] == ' ')
        {
            reverse(s, j, i - 1);
            j = i + 1;
        }
        else if (i == len - 1)
        {
            reverse(s, j, i);
        }
    }

    return s;
}

int main()
{
    char s1[] = "Let's take LeetCode contest";
    printf("Input: \"%s\"\n", s1);
    char *result1 = reverseWords(s1);
    printf("Output: \"%s\"\n", result1);
    free(result1); // Free the allocated memory

    char s2[] = "Mr Ding";
    printf("Input: \"%s\"\n", s2);
    char *result2 = reverseWords(s2);
    printf("Output: \"%s\"\n", result2);
    free(result2); // Free the allocated memory

    return 0;
}