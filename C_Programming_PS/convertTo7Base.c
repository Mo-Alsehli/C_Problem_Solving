#include <stdlib.h>
#include <math.h>

#define atoa(x) #x

/*
-- Description:
Given an integer num, return a string of its base 7 representation.

Example 1:
Input: num = 100
Output: "202"

Example 2:
Input: num = -7
Output: "-10"

LeetCode: https://leetcode.com/problems/base-7/description/

*/

char *convertToBase7(int num)
{
    int res = 0, i = 0;

    while (num != 0)
    {
        int rem = num % 7;
        res = res + rem * pow(10, i);
        i++;
        num = num / 7;
    }

    char *str = (char *)malloc(20 * sizeof(char));
    printf("%d\n", res);
    sprintf(str, "%d", res);

    return str;
}