/* 
auther: Mohamed Magdi
Language: C++.

-- Description:
Given a string s, return the longest 
palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
 
Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.

LeetCode: https://leetcode.com/problems/longest-palindromic-substring/description/.

-- Solution:
- Expand Around Center: The expandAroundCenter function calculates the length of the palindrome centered at indices (left, right).
- Main Loop: For each character in s, the code attempts to expand around that character for both odd-length (i, i) and even-length (i, i + 1) palindromes.
- Update Longest Palindrome: If a longer palindrome is found, start and maxLength are updated to reflect the new palindrome's starting position and length.

-- Complexity:
- Time Comlexity: O(n^2).
- Space Complexity: O(1).
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLength = 1;

        // Helper function to expand around center and return the length of the palindrome
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1; // Length of the palindrome
        };

        for (int i = 0; i < s.size(); i++) {
            int len1 = expandAroundCenter(i, i);       // Odd length palindrome
            int len2 = expandAroundCenter(i, i + 1);   // Even length palindrome
            int len = std::max(len1, len2);

            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2; // Adjust start to the beginning of the palindrome
            }
        }

        return s.substr(start, maxLength);
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s1 = "babad";
    string result1 = solution.longestPalindrome(s1);
    cout << "Input: " << s1 << "\nLongest Palindromic Substring: " << result1 << endl;

    // Test case 2
    string s2 = "cbbd";
    string result2 = solution.longestPalindrome(s2);
    cout << "Input: " << s2 << "\nLongest Palindromic Substring: " << result2 << endl;

    // Additional test cases
    string s3 = "a";
    string result3 = solution.longestPalindrome(s3);
    cout << "Input: " << s3 << "\nLongest Palindromic Substring: " << result3 << endl;

    string s4 = "ac";
    string result4 = solution.longestPalindrome(s4);
    cout << "Input: " << s4 << "\nLongest Palindromic Substring: " << result4 << endl;

    return 0;
}