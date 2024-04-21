#include <stdio.h>
#include <stdlib.h>

int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    int *result = (int *)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;

    // Create a dictionary to store the next greater element for each element in nums2
    int next_greater[nums2Size];
    int stack[nums2Size];
    int top = -1;

    // Iterate through nums2 from right to left
    for (int i = nums2Size - 1; i >= 0; i--)
    {
        // Pop elements from the stack until we find a greater element or the stack is empty
        while (top != -1 && stack[top] <= nums2[i])
        {
            top--;
        }

        // If there's a greater element, store it in the dictionary
        if (top != -1)
        {
            next_greater[i] = stack[top];
        }
        else
        {
            next_greater[i] = -1;
        }

        // Push the current element onto the stack
        stack[++top] = nums2[i];
    }

    // Get the next greater element for each element in nums1
    for (int i = 0; i < nums1Size; i++)
    {
        for (int j = 0; j < nums2Size; j++)
        {
            if (nums1[i] == nums2[j])
            {
                result[i] = next_greater[j];
                break;
            }
        }
    }

    return result;
}

int main()
{
    int nums1[] = {4, 1, 2};
    int nums2[] = {1, 3, 4, 2};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize;
    int *result = nextGreaterElement(nums1, nums1Size, nums2, nums2Size, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d", result[i]);
        if (i < returnSize - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");

    free(result);
    return 0;
}
