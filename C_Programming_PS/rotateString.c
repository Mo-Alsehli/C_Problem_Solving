/*
-- Description:
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
For example, if s = "abcde", then it will be "bcdea" after one shift.

Example 1:
Input: s = "abcde", goal = "cdeab"
Output: true

Example 2:
Input: s = "abcde", goal = "abced"
Output: false

-- LeetCode: https://leetcode.com/problems/rotate-string/description/

-- Solution:
# Approach
- Create a Variable `temp` with a length of sLen*2.
- Copy `s` string into it and then concatinate `s` with itself.
- Then check if the `goal` string is within the temp string.
# Complexity
- Time complexity: O(n)
- Space complexity: O(1)
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool rotateString(char *s, char *goal)
{
    int len_s = strlen(s);
    int len_goal = strlen(goal);

    if (len_s != len_goal)
    {
        return false;
    }

    // Create a temporary string that contains s concatenated with itself
    char temp[2 * len_s + 1];
    strcpy(temp, s);
    strcat(temp, s);

    // Check if goal is a substring of the concatenated string
    if (strstr(temp, goal) != NULL)
    {
        return true;
    }

    return false;
}

int main()
{
    char s1[] = "abcde";
    char s2[] = "cdeab";

    printf("\nRES: %d", rotateString(s1, s2));

    return 0;
}
