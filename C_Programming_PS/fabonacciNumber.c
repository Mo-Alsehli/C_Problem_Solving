/*
-- Description:
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

LeetCode: https://leetcode.com/problems/fibonacci-number/description/

### Explanation
1. **Base Cases:**
   - If \( n \) is 0, return 0.
   - If \( n \) is 1, return 1.
2. **Recursive Case:**
   - For any other value of \( n \), return `fib(n-1) + fib(n-2)`.

### Example Walkthrough
For `fib(4)`:
1. `fib(4)` calls `fib(3)` and `fib(2)`
2. `fib(3)` calls `fib(2)` and `fib(1)`
3. `fib(2)` calls `fib(1)` and `fib(0)`
4. Base cases: `fib(1) = 1` and `fib(0) = 0`
5. Combining results:
   - `fib(2) = 1 + 0 = 1`
   - `fib(3) = 1 + 1 = 2`
   - `fib(4) = 2 + 1 = 3`

### Complexity Analysis
- **Time Complexity:** \(O(2^n)\) due to the exponential number of recursive calls.
- **Space Complexity:** \(O(n)\) due to the maximum depth of the recursion stack.
*/

/*
-- Dynamic Programming Approach.
```
#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int *dp = (int *)malloc((n + 1) * sizeof(int));
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int result = dp[n];
    free(dp);
    return result;
}
```
-- Iterative Approach:
```
if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0;
    int b = 1;
    int c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
```
*/

int fib(int n)
{
    if (n < 2)
    {
        return n;
    };

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;

    n = 2;
    printf("F(%d) = %d\n", n, fib(n));

    n = 3;
    printf("F(%d) = %d\n", n, fib(n));

    n = 4;
    printf("F(%d) = %d\n", n, fib(n));

    n = 10;
    printf("F(%d) = %d\n", n, fib(n));

    return 0;
}