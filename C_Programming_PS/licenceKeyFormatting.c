#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
-- Description:
ou are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.

We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.
Return the reformatted license key.

Example 1:
Input: s = "5F3Z-2e-9-w", k = 4
Output: "5F3Z-2E9W"
Explanation: The string s has been split into two parts, each part has 4 characters.
Note that the two extra dashes are not needed and can be removed.

LeetCode: https://leetcode.com/problems/license-key-formatting/description/

*/

char convert(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 0x20;
    else
        return c;
}

char *licenseKeyFormatting(char *s, int k)
{
    int len = strlen(s), size = len + len / k + 1, counter = 0;
    char *ans = (char *)calloc(size, sizeof(char));
    ans[--size] = '\0';
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == '-')
            continue;
        ans[--size] = convert(s[i]);
        counter++;
        if (counter == k && i != 0)
        {
            ans[--size] = '-';
            counter = 0;
        }
    }

    if (ans[size] == '-')
        size++;
    return ans + size;
}

int main()
{
    char s1[] = "5F3Z-2e-9-w";
    int k1 = 4;
    char *output1 = licenseKeyFormatting(s1, k1);
    printf("Output 1: %s\n", output1); // Output: "5F3Z-2E9W"

    char s2[] = "2-5g-3-J";
    int k2 = 2;
    char *output2 = licenseKeyFormatting(s2, k2);
    printf("Output 2: %s\n", output2); // Output: "2-5G-3J"

    return 0;
}
