/*
Description:
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1


Solution:
In this code, we define the calculateSquareSum function that takes an integer n as input and calculates the sum of the squares of its digits. We iterate over the digits of n using modulo and integer division and add the square of each digit to the sum. The function returns the final sum.

The isHappy function determines if a number is happy using the Floyd's cycle detection algorithm. We initialize two pointers, slow and fast, to the input number n. Then, we enter a do-while loop where in each iteration, slow moves one step ahead by calculating the square sum once, and fast moves two steps ahead by calculating the square sum twice. If there is a cycle, the slow and fast pointers will eventually meet at the same number. If the number they meet at is 1, we know it's a happy number and return true. Otherwise, if they meet at a number other than 1, it means there is a cycle and the number is not happy, so we return false.
*/

#include <stdio.h>
#include <stdbool.h>

int calculateSquareSum(int n)
{
    int sum = 0;

    while (n > 0)
    {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

bool isHappy(int n)
{
    int slow = n;
    int fast = n;

    do
    {
        slow = calculateSquareSum(slow);
        fast = calculateSquareSum(calculateSquareSum(fast));
    } while (slow != fast);

    return slow == 1;
}

int main()
{
    int n = 2;
    bool isHappyNumber = isHappy(n);

    printf("%s\n", isHappyNumber ? "true" : "false");

    return 0;
}
