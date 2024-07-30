/*
-- Description:
Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.

Example 2:
Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.

leetCode: https://leetcode.com/problems/count-binary-substrings/description/

-- Solution:
# Approach
- Calculate number of consecutive ones or zeros.
- Calculate number of consecutive zeros or ones after it.
- Compare the count of each consecutive substring.

# Complexity
- Time complexity: O(n)
- Space complexity: O(1)

 */

#include <stdio.h>
#include <string.h>

int countBinarySubstrings(char *s)
{
    int onesCount = 0, zerosCount = 0, i;
    int zerosFlag = 0, onesFlag = 0;
    int res = 0;
    int len = strlen(s);
    for (i = 0; i < len; i++)
    {
        if (s[i] == '0')
        {
            if (zerosFlag == 0)
            {
                zerosCount = 0;
            }
            zerosCount++;
            if (onesCount >= zerosCount)
            {
                res++;
            }

            onesFlag = 0;
            zerosFlag = 1;
        }
        else
        {
            if (onesFlag == 0)
            {
                onesCount = 0;
            }
            onesCount++;

            if (zerosCount >= onesCount)
            {
                res++;
            }

            onesFlag = 1;
            zerosFlag = 0;
        }
    }

    return res;
}

int main()
{
    char s1[] = "00110011";
    char s2[] = "10101";

    printf("Test case 1: %d\n", countBinarySubstrings(s1)); // Expected: 6
    printf("Test case 2: %d\n", countBinarySubstrings(s2)); // Expected: 4

    return 0;
}