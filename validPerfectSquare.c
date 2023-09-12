#include <stdio.h>
#include <stdbool.h>

/*
-- Description:
Given a positive integer num, return true if num is a perfect square or false otherwise.
A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
You must not use any built-in library function, such as sqrt.

Example 1:
Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

LeetCode: https://leetcode.com/problems/valid-perfect-square/description/

-- Solution:
--- Using binary search to get a mid which will be the sqare root then if it's integer then the number is perfect square root.

-- Time and space complexities:
TIME Complexity: O(log(n))
SPACE Complexity: O(1)

*/

bool isPerfectSquare(int num)
{
    if (num == 0 || num == 1)
        return true;

    int left = 0, right = num;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        long long sqr = (long long)mid * mid;

        if (sqr == num)
        {
            if ((int)mid == mid)
                return true;

            return false;
        }

        if (sqr < num)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return false;
}

int main()
{
    int x = 16;
    int result = isPerfectSquare(x);
    if (result == true)
        printf("The square %d is Perfect Square\n", x);
    else
        printf("The square %d is NOT Perfect Square\n", x);

    return 0;
}
