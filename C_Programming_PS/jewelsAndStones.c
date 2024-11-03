/*
-- Description:
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.
Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Example 2:
Input: jewels = "z", stones = "ZZ"
Output: 0

LeetCode:

-- Solution:
Make a Hasmap and store all occurences in Stones[].
Loop through jewels and add corresponding number of stones
to the corresponding Jewel to the Result.

Complexity
Time complexity: O(N + M)
Space complexity: O(1)
*/

#include <stdio.h>
#include <string.h>

int numJewelsInStones(char *jewels, char *stones)
{
    char hashMap[52] = {0};
    int i = 0, res = 0;
    for (i = 0; i < strlen(stones); i++)
    {
        if (stones[i] >= 65 && stones[i] <= 90)
        {
            hashMap[stones[i] - 'A']++;
        }
        else if (stones[i] >= 97 && stones[i] <= 122)
        {
            hashMap[(stones[i] - 'a') + 26]++;
        }
    }

    for (i = 0; i < strlen(jewels); i++)
    {
        if (jewels[i] >= 65 && jewels[i] <= 90)
        {
            res += hashMap[jewels[i] - 'A'];
        }
        else if (jewels[i] >= 97 && jewels[i] <= 122)
        {
            res += hashMap[(jewels[i] - 'a') + 26];
        }
    }

    return res;
}

int main()
{
    // Example 1
    char jewels1[] = "aA";
    char stones1[] = "aAAbbbb";
    printf("Output 1: %d\n", numJewelsInStones(jewels1, stones1)); // Output: 3

    // Example 2
    char jewels2[] = "z";
    char stones2[] = "ZZ";
    printf("Output 2: %d\n", numJewelsInStones(jewels2, stones2)); // Output: 0

    return 0;
}