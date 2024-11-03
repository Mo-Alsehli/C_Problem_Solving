#include <stdio.h>

/*
Decsription:
Given an integer n, return true if it is a power of three. Otherwise, return false.
An integer n is a power of three, if there exists an integer x such that n == 3x.

Example 1:

Input: n = 27
Output: true
Explanation: 27 = 33

leetCode: https://leetcode.com/problems/power-of-three/description/

*/

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfThree(int n)
{
    if (n <= 0)
    {
        return false;
    }

    while (n > 1)
    {
        if (n % 3 != 0)
        {
            return false;
        }
        n /= 3;
    }

    return true;
}

int main()
{
    int n1 = 27;
    int n2 = 0;
    int n3 = -1;

    printf("isPowerOfThree(%d): %s\n", n1, isPowerOfThree(n1) ? "true" : "false");
    printf("isPowerOfThree(%d): %s\n", n2, isPowerOfThree(n2) ? "true" : "false");
    printf("isPowerOfThree(%d): %s\n", n3, isPowerOfThree(n3) ? "true" : "false");

    return 0;
}
