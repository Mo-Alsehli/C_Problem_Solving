#include <stdio.h>
#include <stdlib.h>

/*
-- Description:
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

LeetCode: https://leetcode.com/problems/intersection-of-two-arrays/description/

-- Solution:
- Approach:
* Both nums1 and nums2 are sorted using the qsort function. This is important to make sure the elements are in the right order for the XOR operation.
* The i and j pointers are used to traverse nums1 and nums2, respectively.
* Whenever a common element is found, it's XORed into the result array. Duplicates are skipped.
-- Complexity
- Time complexity: O(n * log(n)) .. where n = nums1Size + nums2Size
- Space complexity: O(k) .. where k = Max(nums1Size, nums2Size)
*/

// The cmp function is a comparison function used by the qsort function from the C Standard Library. It's used to compare two elements when sorting an array. The purpose of this function is to tell qsort how to order elements in the array.
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    // Sort both arrays to prepare for the XOR operation
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);

    int *result = malloc(sizeof(int) * nums1Size); // The maximum possible size
    int resultSize = 0;

    int i = 0, j = 0;

    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] < nums2[j])
        {
            i++;
        }
        else if (nums1[i] > nums2[j])
        {
            j++;
        }
        else
        {
            // XOR the common element into the result array
            result[resultSize++] = nums1[i];
            i++;
            j++;

            // Skip duplicate elements
            while (i < nums1Size && nums1[i] == nums1[i - 1])
            {
                i++;
            }

            while (j < nums2Size && nums2[j] == nums2[j - 1])
            {
                j++;
            }
        }
    }

    *returnSize = resultSize;
    return result;
}

int main()
{
    int nums1[] = {1, 2, 2, 1};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {2, 2};
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    int returnSize;
    int *result = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);

    printf("Intersection: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}
