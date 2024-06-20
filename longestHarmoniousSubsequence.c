/*
-- Description:
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].

Example 2:
Input: nums = [1,2,3,4]
Output: 2

Example 3:
Input: nums = [1,1,1,1]
Output: 0

Constraints:
1 <= nums.length <= 2 * 10^4
-10^9 <= nums[i] <= 10^9

LeetCode: https://leetcode.com/problems/longest-harmonious-subsequence/description/

-- Time Complexity: O(nlogn)
-- Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int getCount(int *nums, int n, int currEl, int nextEl)
{
    int count = 0, i;

    for (i = 0; i < n; i++)
    {
        if (nums[i] == currEl || nums[i] == nextEl)
            count++;
    }

    return count;
}

int findLHS(int *nums, int numsSize)
{
    int max = 0, i;
    qsort(nums, numsSize, sizeof(int), cmp);

    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i + 1] - nums[i] == 1)
        {
            int count = getCount(nums, numsSize, nums[i], nums[i + 1]);
            if (count > max)
            {
                max = count;
            }
        }
    }
    return max;
}

int main()
{
    int nums1[] = {1, 3, 2, 2, 5, 2, 3, 7};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output: %d\n", findLHS(nums1, size1)); // Expected output: 5

    int nums2[] = {1, 2, 3, 4};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output: %d\n", findLHS(nums2, size2)); // Expected output: 2

    int nums3[] = {1, 1, 1, 1};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Output: %d\n", findLHS(nums3, size3)); // Expected output: 0

    return 0;
}