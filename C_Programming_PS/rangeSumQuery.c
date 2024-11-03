#include <stdio.h>
#include <stdlib.h>

/*
Description:
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

Example 1:

Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

leetCode: https://leetcode.com/problems/range-sum-query-immutable/description/

*/

struct NumArray
{
    int *prefixSums;
    int size;
};

struct NumArray *numArrayCreate(int *nums, int numsSize)
{
    struct NumArray *numArr = (struct NumArray *)malloc(sizeof(struct NumArray));
    numArr->prefixSums = (int *)malloc((numsSize + 1) * sizeof(int));
    numArr->size = numsSize;

    numArr->prefixSums[0] = 0;
    for (int i = 0; i < numsSize; i++)
    {
        numArr->prefixSums[i + 1] = numArr->prefixSums[i] + nums[i];
    }

    return numArr;
}

int numArraySumRange(struct NumArray *obj, int left, int right)
{
    return obj->prefixSums[right + 1] - obj->prefixSums[left];
}

void numArrayFree(struct NumArray *obj)
{
    free(obj->prefixSums);
    free(obj);
}

int main()
{
    int nums[] = {-2, 0, 3, -5, 2, -1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    struct NumArray *numArray = numArrayCreate(nums, numsSize);

    printf("sumRange(0, 2): %d\n", numArraySumRange(numArray, 0, 2));
    printf("sumRange(2, 5): %d\n", numArraySumRange(numArray, 2, 5));
    printf("sumRange(0, 5): %d\n", numArraySumRange(numArray, 0, 5));

    numArrayFree(numArray);

    return 0;
}
