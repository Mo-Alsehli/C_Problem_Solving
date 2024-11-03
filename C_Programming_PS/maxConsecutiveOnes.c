/*
- Auther: Mohamed Magdi
- Date: 14-4-2024

- Description:
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2

- LeetCode: https://leetcode.com/problems/max-consecutive-ones/

-- Solution:
We define two variables:

max_count: Stores the maximum number of consecutive 1s found so far.
current_count: Tracks the number of consecutive 1s encountered during the current iteration.
We iterate through the nums array using a for loop.

Inside the loop:

If the current element (nums[i]) is 1, we increment current_count.
If the current element is 0, it breaks the consecutive 1s sequence. We compare the current count (current_count) with max_count and update max_count if necessary. We then reset current_count to 0 for the next sequence.
After the loop finishes, we need to handle the case where the maximum consecutive 1s are at the end of the array. We compare current_count with max_count one last time and update max_count if needed.

Finally, the function returns max_count, which represents the maximum number of consecutive 1s found in the array.

- Time Complexity (O(n))
- Space Complexity (O(1))

*/

#include <stdio.h>

int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int currCount = 0, maxCount = 0, i = 0;

    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            currCount++;
        }
        else if (nums[i] == 0)
        {
            if (maxCount < currCount)
            {
                maxCount = currCount;
                currCount = 0;
            }
            else
            {
                currCount = 0;
            }
        }
    }
    if (maxCount < currCount)
    {
        maxCount = currCount;
    }

    return maxCount;
}

int main()
{
    int nums[] = {1, 1, 0, 1, 1, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int maxConsecutiveOnes = findMaxConsecutiveOnes(nums, n);
    printf("Maximum consecutive 1s: %d\n", maxConsecutiveOnes);

    return 0;
}
