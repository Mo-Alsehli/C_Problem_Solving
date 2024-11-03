/*
-- Description:
- You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

Example:
Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.

-- Solution:
- We track the rest of coins after each column.
- Then if the rest becomes less than the number of row we return the row.

-- There is another solution idea using binary search

*/

#include <stdio.h>

/* int arrangeCoins(int n) {
    long long left = 0, right = n;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long sum = (mid * (mid + 1)) / 2;  // Sum of the first 'mid' rows

        if (sum == n) {
            return (int)mid;
        } else if (sum < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return (int)right;  // If there's an incomplete row, return the last complete row
} */

int arrangeCoins(int n)
{
    int curr = n, row = 0;

    while (curr > 0)
    {
        if (curr <= row)
        {
            return row;
        }
        row++;
        curr -= row;
    }

    return row;
}

int main()
{
    int n = 5;
    int result = arrangeCoins(n);
    printf("%d\n", result);

    return 0;
}