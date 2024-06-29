/*
-- Description:
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6

Example 2:
Input: nums = [1,2,3,4]
Output: 24

Example 3:
Input: nums = [-1,-2,-3]
Output: -6

-- LeetCode: https://leetcode.com/problems/maximum-product-of-three-numbers/description/

-- Solution:
# Approach
- Get the three max Positive integer.
- Get the two min Negative integers.
- Get the max product.

# Complexity
- Time complexity: O(N)

- Space complexity: O(1)
 */

#include <stdio.h>

int maximumProduct(int *nums, int numsSize)
{
    int firstMaxP = -1000, secondMaxP = -1000, thirdMaxP = -1000;
    int i, maxPositive = 0;

    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > thirdMaxP)
        {
            thirdMaxP = nums[i];
        }

        if (thirdMaxP > secondMaxP)
        {
            secondMaxP = secondMaxP ^ thirdMaxP;
            thirdMaxP = secondMaxP ^ thirdMaxP;
            secondMaxP = secondMaxP ^ thirdMaxP;
        }

        if (secondMaxP > firstMaxP)
        {
            firstMaxP = firstMaxP ^ secondMaxP;
            secondMaxP = firstMaxP ^ secondMaxP;
            firstMaxP = firstMaxP ^ secondMaxP;
        }
    }

    maxPositive = firstMaxP * secondMaxP * thirdMaxP;

    int maxUsingNegative = 0;
    int firstMinN = 1000, secondMinN = 1000;

    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] < secondMinN)
        {
            secondMinN = nums[i];
        }

        if (secondMinN < firstMinN)
        {
            firstMinN = firstMinN ^ secondMinN;
            secondMinN = firstMinN ^ secondMinN;
            firstMinN = firstMinN ^ secondMinN;
        }
    }

    maxUsingNegative = firstMaxP * firstMinN * secondMinN;

    return maxPositive > maxUsingNegative ? maxPositive : maxUsingNegative;
}

int main()
{
    // Example 1
    int nums1[] = {1, 2, 3};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output 1: %d\n", maximumProduct(nums1, size1)); // Output: 6

    // Example 2
    int nums2[] = {1, 2, 3, 4};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output 2: %d\n", maximumProduct(nums2, size2)); // Output: 24

    // Example 3
    int nums3[] = {-1, -2, -3};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Output 3: %d\n", maximumProduct(nums3, size3)); // Output: -6

    return 0;
}
