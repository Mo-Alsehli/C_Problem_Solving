#include <stdio.h>
#include <stdlib.h>

/*
-- Description:
- Given an integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.
All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.
Note: You are not allowed to use any built-in library method to directly solve this problem.

Example 1:
Input: num = 26
Output: "1a"

Example 2:
Input: num = -1
Output: "ffffffff"

-- LeetCode: https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
 */

char *toHex(int num)
{
    if (num == 0)
    {
        return "0";
    }
    char hex[] = "0123456789abcdef";
    char *res = (char *)malloc(sizeof(char) * 9);

    int mask = 0xf;
    int shift = 28;
    int i = 0, count = 0;

    for (i = 0; i < 8; i++)
    {
        int digit = (num >> shift) & mask;
        res[i] = hex[digit];
        shift -= 4;
    }

    while (res[count] == '0')
    {
        count++;
    }

    if (count > 0)
    {
        for (i = 0; i < count && count < 8; i++)
        {
            res[i] = res[count];
            count++;
        }
        res[i] = '\0';
    }
    else
    {
        res[8] = '\0';
    }

    return res;
}

int main()
{
    int num1 = 26;
    int num2 = -1;

    char *hex1 = toHex(num1);
    char *hex2 = toHex(num2);

    printf("Hexadecimal representation of %d: %s\n", num1, hex1);
    printf("Hexadecimal representation of %d: %s\n", num2, hex2);

    free(hex1);
    free(hex2);

    return 0;
}
