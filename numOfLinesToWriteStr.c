/*
-- Description:
You are given a string s of lowercase English letters and an array widths denoting how many pixels wide each lowercase English letter is. Specifically, widths[0] is the width of 'a', widths[1] is the width of 'b', and so on.

You are trying to write s across several lines, where each line is no longer than 100 pixels. Starting at the beginning of s, write as many letters on the first line such that the total width does not exceed 100 pixels. Then, from where you stopped in s, continue writing as many letters as you can on the second line. Continue this process until you have written all of s.

Return an array result of length 2 where:
result[0] is the total number of lines.
result[1] is the width of the last line in pixels.

Example 1:
Input: widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10], s = "abcdefghijklmnopqrstuvwxyz"
Output: [3,60]
Explanation: You can write s as follows:
abcdefghij  // 100 pixels wide
klmnopqrst  // 100 pixels wide
uvwxyz      // 60 pixels wide
There are a total of 3 lines, and the last line is 60 pixels wide.

Example 2:
Input: widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10], s = "bbbcccdddaaa"
Output: [2,4]
Explanation: You can write s as follows:
bbbcccdddaa  // 98 pixels wide
a            // 4 pixels wide
There are a total of 2 lines, and the last line is 4 pixels wide.

LeetCode: https://leetcode.com/problems/number-of-lines-to-write-string/description/

-- Solution:
# Approach
- Create `pixels` Variable and Loop through `s` String.
- Increment `pixels` variable by adjusant number of pixels in `widths`.
- Make a condition to check if `pixels` equals or more than 100.

# Complexity
- Time complexity: **O(n)**
- Space complexity: **O(1)**
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *numberOfLines(int *widths, int widthsSize, char *s, int *returnSize)
{
    int *res = (int *)malloc(sizeof(int) * 2);
    res[0] = 0;
    *returnSize = 2;
    int sLen = strlen(s);
    int pixels = 0;

    for (int i = 0; i < sLen; i++)
    {
        pixels += widths[s[i] - 'a'];
        if (pixels == 100)
        {
            res[0]++;
            pixels = 0;
        }
        else if (pixels > 100)
        {
            res[0]++;
            pixels = widths[s[i] - 'a'];
        }
    }
    if (pixels == 0)
    {
        res[1] = 100;
    }
    else
    {
        res[0]++;
        res[1] = pixels;
    }

    return res;
}

int main()
{
    int widths1[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    char s1[] = "abcdefghijklmnopqrstuvwxyz";
    int returnSize1;
    int *result1 = numberOfLines(widths1, 26, s1, &returnSize1);
    printf("Output: [%d, %d]\n", result1[0], result1[1]); // Output: [3, 60]

    int widths2[] = {4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    char s2[] = "bbbcccdddaaa";
    int returnSize2;
    int *result2 = numberOfLines(widths2, 26, s2, &returnSize2);
    printf("Output: [%d, %d]\n", result2[0], result2[1]); // Output: [2, 4]

    return 0;
}
