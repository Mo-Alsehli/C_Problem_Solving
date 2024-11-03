/*
Third Maximum Element

-- Description:
- Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

Example 1:
Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.

Example 2:
Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.

-- Solution:
- The function then iterates through the given array (nums).
-For each element in the array, it checks whether the element is greater than first, greater than second but less than first, and greater than third but less than second.
- NOTE:
-- The LONG_MIN macro is defined in the <limits.h> header file in C. It represents the minimum value that can be stored in an object of type long

-- Complexity:
- Time: O(n).
- Space: O(1).
*/

#include <stdio.h>
#include <limits.h>

int thirdMax(int *nums, int numsSize)
{
    long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] > first)
        {
            third = second;
            second = first;
            first = nums[i];
        }
        else if (nums[i] < first && nums[i] > second)
        {
            third = second;
            second = nums[i];
        }
        else if (nums[i] < second && nums[i] > third)
        {
            third = nums[i];
        }
    }

    return (third == LONG_MIN) ? first : third;
}

int main()
{
    int nums1[] = {3, 2, 1};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output 1: %d\n", thirdMax(nums1, numsSize1));

    int nums2[] = {1, 2};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output 2: %d\n", thirdMax(nums2, numsSize2));

    return 0;
}
