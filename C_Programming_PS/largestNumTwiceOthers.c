/*
-- Description:
ou are given an integer array nums where the largest integer is unique.
Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest element, or return -1 otherwise.

Example 1:
Input: nums = [3,6,1,0]
Output: 1
Explanation: 6 is the largest integer.
For every other number in the array x, 6 is at least twice as big as x.
The index of value 6 is 1, so we return 1.

Example 2:
Input: nums = [1,2,3,4]
Output: -1
Explanation: 4 is less than twice the value of 3, so we return -1.

-- LeetCode: https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/

-- Solution:
# Approach
- Make variables for the top largest and second largest elements in the array.
- Iterate over the array.
- Assign the values of the largest, largestIndex and second largest.
- compare the value of largest with secondLargest*2

# Complexity
- Time complexity: O(n)
- Space complexity: O(1)

*/

#include <stdio.h>

int dominantIndex(int *nums, int numsSize)
{
    int largest = nums[0], secondLargest = 0, index = 0;

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > largest)
        {
            secondLargest = largest;
            largest = nums[i];
            index = i;
        }
        else if (nums[i] > secondLargest)
        {
            secondLargest = nums[i];
        }
    }

    return largest >= (2 * secondLargest) ? index : -1;
}

int main()
{
    int nums1[] = {3, 6, 1, 0};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output for Example 1: %d\n", dominantIndex(nums1, size1));

    int nums2[] = {1, 2, 3, 4};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output for Example 2: %d\n", dominantIndex(nums2, size2));

    return 0;
}