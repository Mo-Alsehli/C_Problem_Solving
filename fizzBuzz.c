/*
-- Description:
Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.

Example 1:
Input: n = 3
Output: ["1","2","Fizz"]

LeetCode: https://leetcode.com/problems/fizz-buzz/description/

-- Solution:
This program defines a fizzBuzz function that generates the FizzBuzz sequence up to the given number n. The main function then demonstrates how to use this function and prints the result.

-- Space Complexity: O(n)

-- Time Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

char **fizzBuzz(int n, int *returnSize)
{
    // Allocate memory for the result array
    char **result = (char **)malloc(n * sizeof(char *));
    *returnSize = n;

    for (int i = 1; i <= n; ++i)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            // Divisible by both 3 and 5
            result[i - 1] = "FizzBuzz";
        }
        else if (i % 3 == 0)
        {
            // Divisible by 3
            result[i - 1] = "Fizz";
        }
        else if (i % 5 == 0)
        {
            // Divisible by 5
            result[i - 1] = "Buzz";
        }
        else
        {
            // Not divisible by 3 or 5
            // Convert the number to a string
            int length = snprintf(NULL, 0, "%d", i);
            result[i - 1] = (char *)malloc((length + 1) * sizeof(char));
            snprintf(result[i - 1], length + 1, "%d", i);
        }
    }

    return result;
}

int main()
{
    int n = 15;
    int returnSize;

    char **result = fizzBuzz(n, &returnSize);

    // Print the result array
    for (int i = 0; i < returnSize; ++i)
    {
        printf("%s, ", result[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < returnSize; ++i)
    {
        free(result[i]);
    }
    free(result);

    return 0;
}
