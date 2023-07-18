/*
Description:
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

LeetCode: https://leetcode.com/problems/power-of-two

Solution:
- To check if an integer n is a power of two, we can use bitwise operations. A power of two in binary form has only one bit set to 1, and all other bits are 0. So, if n is a power of two, it should satisfy the condition n & (n - 1) == 0.
- Now, let's analyze the condition n & (n - 1) == 0 in the isPowerOfTwo function:

For n equal to 1:

n = 1 (binary: 00000001)
n - 1 = 0 (binary: 00000000)
n & (n - 1) = 00000001 & 00000000 = 00000000
For n equal to 2:

n = 2 (binary: 00000010)
n - 1 = 1 (binary: 00000001)
n & (n - 1) = 00000010 & 00000001 = 00000000
For n equal to 4:

n = 4 (binary: 00000100)
n - 1 = 3 (binary: 00000011)
n & (n - 1) = 00000100 & 00000011 = 00000000
For n equal to 8:

n = 8 (binary: 00001000)
n - 1 = 7 (binary: 00000111)
n & (n - 1) = 00001000 & 00000111 = 00000000

*/

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n)
{
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main()
{
    int n = 16;

    bool result = isPowerOfTwo(n);

    printf("%d is a power of two: %s\n", n, result ? "true" : "false");

    return 0;
}
