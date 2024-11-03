#include <stdio.h>

/*
-- Description:
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

leetcode: https://leetcode.com/problems/move-zeroes/description/
myLeetcode: https://leetcode.com/Mohamed_Magdi/

Solution:

The variable nonZeroIndex keeps track of the position where the next non-zero element should be placed. We iterate through the array, and if the current element is non-zero, we move it to the nonZeroIndex position and increment nonZeroIndex.

After moving all the non-zero elements to their correct positions, we fill the remaining positions with zeros to ensure that all zeros are moved to the end of the array.

*/

void moveZeros(int nums[], int numsSize)
{
    int nonZeroIndex = 0;

    // Iterate through the array
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            // Move non-zero element to the nonZeroIndex position
            nums[nonZeroIndex] = nums[i];

            // If the current index is different from the nonZeroIndex, set the current index to zero

            if (i != nonZeroIndex)
            {
                nums[i] = 0;
            }

            nonZeroIndex++;
        }
        printf("i = %d, nonZeroIndex = %d\n", i, nonZeroIndex);
    }
}

int main()
{
    int nums[] = {0, 1, 0, 3, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Original Array: ");
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    moveZeros(nums, numsSize);

    printf("Modified Array: ");
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
