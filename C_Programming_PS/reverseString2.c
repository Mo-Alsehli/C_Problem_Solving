/*
-- Description:
Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

Example 1:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Example 2:
Input: s = "abcd", k = 2
Output: "bacd"

LeetCode: https://leetcode.com/problems/reverse-string-ii/description/

-- Solution:
# Approach
- Traverse the string in chunks of 2k characters.
- For each chunk, reverse the first k characters.
- If there are fewer than k characters left, reverse all of them.
- If there are between k and 2k characters, reverse the first k characters and leave the rest as is.

# Complexity
- Time complexity: O(n)

- Space complexity: O(1)

 */

void reverse(char *start, char *end)
{
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

char *reverseStr(char *s, int k)
{
    int len = strlen(s);
    for (int i = 0; i < len; i += (2 * k))
    {
        int end = ((i + k - 1 < len) ? i + k - 1 : len - 1);
        reverse(s + i, s + end);
    }
    return s;
}

int main()
{
    char s1[] = "abcdefg";
    int k1 = 2;
    printf("Input: %s, k = %d\n", s1, k1);
    printf("Output: %s\n", reverseStr(s1, k1)); // Output should be "bacdfeg"

    char s2[] = "abcd";
    int k2 = 2;
    printf("Input: %s, k = %d\n", s2, k2);
    printf("Output: %s\n", reverseStr(s2, k2)); // Output should be "bacd"

    return 0;
}