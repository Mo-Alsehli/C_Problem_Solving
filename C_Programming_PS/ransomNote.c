#include <stdio.h>
#include <string.h>

/*
-- Description:
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true

LeetCode: https://leetcode.com/problems/ransom-note/description/
*/

// Function to check if ransomNote can be constructed from magazine
int canConstruct(char *ransomNote, char *magazine)
{
    int char_count[26] = {0}; // Initialize an array to count characters (assuming lowercase English letters)

    // Count characters in magazine
    for (int i = 0; i < strlen(magazine); i++)
    {
        char_count[magazine[i] - 'a']++;
    }

    // Check if characters in ransomNote can be constructed from magazine
    for (int i = 0; i < strlen(ransomNote); i++)
    {
        if (char_count[ransomNote[i] - 'a'] == 0)
        {
            return 0; // Cannot construct ransomNote
        }
        char_count[ransomNote[i] - 'a']--;
    }

    return 1; // Can construct ransomNote
}

int main()
{
    char ransomNote1[] = "a";
    char magazine1[] = "b";
    printf("%d\n", canConstruct(ransomNote1, magazine1)); // Output: 0 (False)

    char ransomNote2[] = "aa";
    char magazine2[] = "ab";
    printf("%d\n", canConstruct(ransomNote2, magazine2)); // Output: 0 (False)

    char ransomNote3[] = "aa";
    char magazine3[] = "aab";
    printf("%d\n", canConstruct(ransomNote3, magazine3)); // Output: 1 (True)

    return 0;
}
