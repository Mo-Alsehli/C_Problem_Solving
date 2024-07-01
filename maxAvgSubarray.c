/*
-- Description:
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:
Input: nums = [5], k = 1
Output: 5.00000

LeetCode: https://leetcode.com/problems/maximum-average-subarray-i/description/

-- Solution:
# Approach
## Sliding Window Technique
### Initialize the Window:
- First, calculate the sum of the first 𝑘.
- This will be our initial window sum.
### Slide the Window:
- Move the window one element at a time from the start of the array to the end.
- For each move, subtract the element that is left behind and add the new element that comes into the window.
- Track the maximum sum encountered during this process.
### Calculate the Average:
- The maximum average can then be obtained by dividing the maximum sum by 𝑘.
-
# Complexity
- Time complexity: `O(n)`

- Space complexity: `O(1)`

 */

#include "stdio.h"

double findMaxAverage(int *nums, int numsSize, int k)
{
    double maxAvg = 0, currAvg = 0.0;
    int i, j;
    if (numsSize > k)
    {
        maxAvg = -10000;
        for (i = 0; i < k; i++, j++)
            currAvg += nums[i];
        maxAvg = currAvg;
        for ((i = 0, j = k); (i < numsSize - k && j < numsSize); (i++, j++))
        {
            currAvg += nums[j];
            currAvg -= nums[i];
            maxAvg = (currAvg > maxAvg ? currAvg : maxAvg);
        }
    }
    else
    {
        for (i = 0; i < numsSize; i++)
            maxAvg += nums[i];
    }

    maxAvg = maxAvg / k;

    return maxAvg;
}

int main()
{
    // Example 1
    int nums1[] = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Example 1: %.5f\n", findMaxAverage(nums1, numsSize1, k1)); // Output: 12.75000

    // Example 2
    int nums2[] = {5};
    int k2 = 1;
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Example 2: %.5f\n", findMaxAverage(nums2, numsSize2, k2)); // Output: 5.00000

    return 0;
}