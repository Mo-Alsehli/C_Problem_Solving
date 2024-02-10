/*
-- Description:
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Example 1:
Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.

-- Solution:
ort the arrays g and s in non-decreasing order. This allows you to easily match the smallest greed factor with the smallest cookie size.

Initialize two pointers, one for iterating through the greed factors (i) and one for iterating through the cookie sizes (j). Start both pointers from the beginning of their respective sorted arrays.

Iterate through the sorted arrays:

If the current cookie size s[j] is greater than or equal to the current child's greed factor g[i], it means you can assign this cookie to the child. Move both pointers (i and j) to the next child and cookie respectively.
If the current cookie size s[j] is less than the current child's greed factor g[i], it means the current cookie is too small for the child. Move only the pointer for cookies (j) to the next cookie.
Keep track of the number of content children while iterating. This number represents the maximum number of content children you can achieve.

After iterating through both arrays, return the count of content children

-- Time Complexity: O(nlogn)
-- Space Complexity: O(logn)

leetCode: https://leetcode.com/problems/assign-cookies/description/

*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int findContentChildren(int *g, int gSize, int *s, int sSize)
{
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    int smallerSize = gSize < sSize ? gSize : sSize;
    int i, j;

    int output = 0;

    for (i = 0, j = 0; (i < gSize && j < sSize);)
    {
        if (s[j] >= g[i])
        {
            output++;
            i++;
        }
        j++;
    }

    return output;
}

int main()
{
    int g[] = {1, 2, 3};
    int s[] = {1, 1};
    int gSize = sizeof(g) / sizeof(g[0]);
    int sSize = sizeof(s) / sizeof(s[0]);

    printf("Maximum number of content children: %d\n", findContentChildren(g, gSize, s, sSize));

    return 0;
}