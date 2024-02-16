/*
-- Description:
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

Example 1:
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:
Input: s = "aba"
Output: false

-- Solution:
1.We start by iterating through the possible lengths of substrings from 1 to half the length of the input string s. We don't need to consider substrings longer than half the length of s because we're looking for repeating patterns.

2.For each substring length len, we check if len evenly divides the length of the string s. If it does not, then it's not possible for s to be formed by repeating a substring of length len.

3.If len evenly divides the length of s, we iterate through the string starting from index len. We compare each character in s with the corresponding character in the substring starting from index 0. If at any point the characters don't match, we know that the substring cannot be repeated to form s.

4.If all characters match for the current substring, we set a boolean variable isRepeated to true. If isRepeated remains true after the loop, it means that the substring can be repeated to form s. In this case, we return true.

5.If no repeating substring is found after trying all possible lengths, we return false.

6. (s[i] == s[i%len]) Explination:
In the code, s[i % len] is used to access characters in the string s cyclically. Here's how it works:

i is the index used to iterate through the string s starting from the lenth character.
% is the modulo operator, which returns the remainder of the division of i by len.
Since i is incremented by 1 in each iteration, i % len cycles through the values from 0 to len - 1, and then starts over from 0 again.
This allows us to repeatedly access characters in s starting from the beginning when i exceeds the length of s.
For example, let's say s = "abcdef" and len = 3. When i is incremented from 0 to 6, i % len will produce the following sequence of values:

i = 0: i % len = 0, so s[0 % 3] refers to the character 'a'.
i = 1: i % len = 1, so s[1 % 3] refers to the character 'b'.
i = 2: i % len = 2, so s[2 % 3] refers to the character 'c'.
i = 3: i % len = 0, so s[3 % 3] also refers to the character 'a'.
i = 4: i % len = 1, so s[4 % 3] refers to the character 'b'.
i = 5: i % len = 2, so s[5 % 3] refers to the character 'c'.
i = 6: i % len = 0, so s[6 % 3] refers to the character 'a'.

LeetCode: https://leetcode.com/problems/repeated-substring-pattern/description/

*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool repeatedSubstringPattern(char *s)
{
    int n = strlen(s);
    for (int len = 1; len <= n / 2; len++)
    {
        if (n % len == 0)
        {
            bool isRepeated = true;
            for (int i = len; i < n; i++)
            {
                if (s[i] != s[i % len])
                {
                    isRepeated = false;
                    break;
                }
            }
            if (isRepeated)
                return true;
        }
    }
    return false;
}

int main()
{
    char *str1 = "abcabcabc";
    char *str2 = "mohamedmagdi";

    if (repeatedSubstringPattern(str1) == 1)
    {
        printf("The string %s has repeated substring\n\n", str1);
    }
    else
    {
        printf("The string %s hasn't repeated substring\n\n", str1);
    }

    if (repeatedSubstringPattern(str2) == 1)
    {
        printf("The string %s has repeated substring\n\n", str2);
    }
    else
    {
        printf("The string %s hasn't repeated substring\n\n", str2);
    }

    return 0;
}
