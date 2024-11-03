#include <stdio.h>
#include <stdbool.h>
#include <ctype.h> // For isalpha
#include <string.h>

/*
-- Description:
Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:
Input: s = "hello"
Output: "holle"

LeetCode: https://leetcode.com/problems/reverse-vowels-of-a-string

Solution:
The isVowel function checks if a character is a vowel, ignoring the case.
The reverseVowels function uses two pointers (left and right) to traverse the string from both ends.
It looks for the next vowel from both directions and swaps them if found.
*/

bool isVowel(char c)
{
    c = tolower(c); // Convert to lowercase to handle both upper and lower case vowels
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void reverseVowels(char *s)
{
    if (!s)
        return;

    int left = 0;
    int right = strlen(s) - 1;

    while (left < right)
    {
        // Find the next vowel from the left
        while (left < right && !isVowel(s[left]))
        {
            left++;
        }
        // Find the next vowel from the right
        while (left < right && !isVowel(s[right]))
        {
            right--;
        }

        // Swap the vowels
        if (left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
}

int main()
{
    char s1[] = "hello";
    printf("Input: %s\n", s1);
    reverseVowels(s1);
    printf("Output: %s\n", s1);

    char s2[] = "leetcode";
    printf("Input: %s\n", s2);
    reverseVowels(s2);
    printf("Output: %s\n", s2);

    return 0;
}

/*
-- Time And Space Complexities:

**Time Complexity:**

The time complexity of the code is O(n), where n is the length of the input string `s`. This is because the code processes each character in the string exactly once. The while loop that iterates through the string runs until the `left` and `right` pointers meet in the middle of the string, and this happens in a linear fashion.
The `isVowel` function, which is called for each character, has constant time complexity because it performs a fixed number of character comparisons.
Therefore, the overall time complexity is dominated by the linear traversal of the string, making it O(n).

**Space Complexity:**

The space complexity is O(1), which means it uses constant extra space. Regardless of the length of the input string, the code uses a fixed amount of additional space for variables like `left`, `right`, `temp`, and `c` (used in the `isVowel` function). These variables do not depend on the size of the input, so the space complexity remains constant.

*/
