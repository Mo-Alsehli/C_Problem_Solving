#include <stdio.h>

/*
-- Description:
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

leetCode: https://leetcode.com/problems/reverse-string/description/

*/

void reverseString(char *s, int sSize)
{
    int left = 0;
    int right = sSize - 1;

    while (left < right)
    {
        // Swap characters at the left and right pointers
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        // Move the pointers towards each other
        left++;
        right--;
    }
}

int main()
{
    char s1[] = {'h', 'e', 'l', 'l', 'o'};
    int s1Size = sizeof(s1) / sizeof(s1[0]);
    reverseString(s1, s1Size);
    printf("Reversed string: ");
    for (int i = 0; i < s1Size; i++)
    {
        printf("%c ", s1[i]);
    }
    printf("\n");

    char s2[] = {'H', 'a', 'n', 'n', 'a', 'h'};
    int s2Size = sizeof(s2) / sizeof(s2[0]);
    reverseString(s2, s2Size);
    printf("Reversed string: ");
    for (int i = 0; i < s2Size; i++)
    {
        printf("%c ", s2[i]);
    }
    printf("\n");

    return 0;
}
