/*
## Mohamed Magdi
## 26 MAY 2024
## Detect Capital Use Problem.

-- Description:
We define the usage of capitals in a word to be right when one of the following cases holds:
All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

Example 1:
Input: word = "USA"
Output: true

Example 2:
Input: word = "FlaG"
Output: false

LeetCode: https://leetcode.com/problems/detect-capital/description/

-- Solution:
- We first Check if the first character is uppercase.
    - if It's uppercase we check if the second is uppercase.
    - if the 2nd is uppercase we iterate over string and if there is any lowercase letter then we return false.
    - if the 2nd isn't uppercase we iterate over string and if there is any uppercase we return false.
- if 1st letter isn't uppercase we iterate over string and check if there is any upper case we return false.
- Then if all these cases passed we return true.

# Complexity
- Time complexity: O(n)

- Space complexity: O(1)

*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool detectCapitalUse(char *word)
{
    int i = 0;
    int len = strlen(word);
    if (word[0] >= 'A' && word[0] <= 'Z')
    {
        if (len == 1)
            return true;
        if (word[1] >= 'A' && word[1] <= 'Z')
        {
            for (i = 1; i < len; i++)
            {
                if (word[i] > 'Z')
                {
                    return false;
                }
            }
        }
        else
        {
            for (i = 1; i < len; i++)
            {
                if (word[i] <= 'Z')
                {
                    return false;
                }
            }
        }
    }
    else
    {
        for (i = 1; i < len; i++)
        {
            if (word[i] <= 'Z')
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    char word1[] = "USA";
    char word2[] = "FlaG";
    char word3[] = "Google";
    char word4[] = "leetcode";

    printf("%s -> %s\n", word1, detectCapitalUse(word1) ? "true" : "false");
    printf("%s -> %s\n", word2, detectCapitalUse(word2) ? "true" : "false");
    printf("%s -> %s\n", word3, detectCapitalUse(word3) ? "true" : "false");
    printf("%s -> %s\n", word4, detectCapitalUse(word4) ? "true" : "false");

    return 0;
}