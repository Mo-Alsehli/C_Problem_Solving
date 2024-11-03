/*
-- Description:
A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

Given an integer n, return true if n is a perfect number, otherwise return false.

Example 1:
Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.

Example 2:
Input: num = 7
Output: false

LeetCode: https://leetcode.com/problems/perfect-number/description/
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool checkPerfectNumber(int num)
{
    if (num <= 1)
        return false; // No perfect number less than or equal to 1

    int sum = 1; // 1 is a divisor for all integers

    // Iterate from 2 to sqrt(num)
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            sum += i;
            if (i != num / i)
            {
                sum += num / i;
            }
        }
    }

    return sum == num;
}

int main()
{
    int num = 28;
    if (checkPerfectNumber(num))
    {
        printf("%d is a perfect number.\n", num);
    }
    else
    {
        printf("%d is not a perfect number.\n", num);
    }

    num = 7;
    if (checkPerfectNumber(num))
    {
        printf("%d is a perfect number.\n", num);
    }
    else
    {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;
}
