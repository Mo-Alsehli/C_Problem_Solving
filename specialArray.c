#include <string.h>
#include <stdio.h>

/*
-- Description:
You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.



Example 1:

Input: nums = [3,5]
Output: 2
Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.
Example 2:

Input: nums = [0,0]
Output: -1
Explanation: No numbers fit the criteria for x.
If x = 0, there should be 0 numbers >= x, but there are 2.
If x = 1, there should be 1 number >= x, but there are 0.
If x = 2, there should be 2 numbers >= x, but there are 0.
x cannot be greater since there are only 2 numbers in nums.
Example 3:

Input: nums = [0,4,3,0,4]
Output: 3
Explanation: There are 3 values that are greater than or equal to 3.
 */

int specialArray(int *nums, int numsSize)
{
    int i, j;
    int specialCount = 0;

    for (i = 1; i <= numsSize; i++)
    {
        for (j = 0; j < numsSize; j++)
        {
            if (nums[j] >= i)
            {
                specialCount++;
            }
        }
        // printf("%d, %d\n", specialCount, i);
        if (specialCount == i)
        {
            return i;
        }
        else
        {
            specialCount = 0;
        }
    }

    return -1;
}

int main()
{
    int nums1[] = {3, 5};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Result for nums1: %d\n", specialArray(nums1, numsSize1)); // Output: 2

    int nums2[] = {0, 0};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Result for nums2: %d\n", specialArray(nums2, numsSize2)); // Output: -1

    int nums3[] = {0, 4, 3, 0, 4};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Result for nums3: %d\n", specialArray(nums3, numsSize3)); // Output: 3

    return 0;
}