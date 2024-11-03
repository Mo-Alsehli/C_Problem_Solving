#include <stdio.h>
#include <math.h>

/*
Description:
Given an integer n, return true if it is a power of four. Otherwise, return false.
An integer n is a power of four, if there exists an integer x such that n == 4x.

Example 1:
Input: n = 16
Output: true

Example 2:
Input: n = 5
Output: false

Leetcode: https://leetcode.com/problems/power-of-four/description/

Solution:
- First we check if there is one bit that is set in the number (number is power of two).
- Then we check if this bit is in a positive position in the number.
*/

int isPowerOfFour(int n)
{
    if (n <= 0 || (n & n - 1) != 0)
    {
        return 0;
    }

    /*
    if(n % 3 == 1){
        return 1;
    }

    return 0;
    */

    double position = log2(n);

    return ((position == (int)position) && ((int)position % 2 == 0));
}

int isPowerOf4(int num)
{
    // A = 1010 -> toggles bits in negative postions.
    return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0xAAAAAAAA) == 0);
}

int main()
{
    int num = 16;

    if (isPowerOfFour(num) == 1)
    {
        printf("%d is power of four :)\n", num);
    }
    else
    {
        printf("%d is not power of four ):\n", num);
    }

    return 0;
}
