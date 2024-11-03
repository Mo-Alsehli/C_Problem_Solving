#include <stdio.h>
#include <string.h>

/* 17 NOV 2023
-- Description:
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Example 1:
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

LeetCode: https://leetcode.com/problems/longest-palindrome/description/

-- Solution:
We use an array count to store the count of each character.
We iterate through the string to count the occurrences of each character.
We calculate the length of the palindrome based on the counts, adding even counts and handling the case of at most one character with an odd count.

Time Complexity: O(n).
Space Complexity: O(1)
*/

// First Solution.
/*
int cmp(const void *a, const void *b){
    return (*(char*)a - *(char*)b);
}

int longestPalindrome(char* s) {
    int longest = 0, i, l = strlen(s);
    qsort(s, l, sizeof(char), cmp);
    for(i = 0; i < l; i++){
        if(s[i] == s[i+1]){
            longest += 2;
            i += 1;
        }else {
            flag = 1;
        }
    }
    if(flag == 1){
        longest++;
    }

    return longest;
*/

// Second Solution:
int longestPalindrome(char *s)
{
    // Initialize an array to store the count of each character.
    int count[128] = {0}; // Assuming ASCII characters.

    // Count the occurrences of each character.
    for (int i = 0; s[i] != '\0'; i++)
    {
        count[s[i]]++;
    }

    int length = 0;
    int oddCount = 0;

    // Calculate the length of the palindrome.
    for (int i = 0; i < 128; i++)
    {
        length += count[i] / 2 * 2; // Add even counts.
        oddCount |= count[i] % 2;   // Check for odd counts.
    }

    return length + oddCount;
}

int main()
{
    char s1[] = "abccccdd";
    char s2[] = "a";

    printf("Longest palindrome for \"%s\": %d\n", s1, longestPalindrome(s1));
    printf("Longest palindrome for \"%s\": %d\n", s2, longestPalindrome(s2));

    return 0;
}
