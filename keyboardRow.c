#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*
Auther: Mohamed Magdi
Date: April 26 2024

-- Description:
Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
In the American keyboard:
the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".

Example 1:
Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]

Example 2:
Input: words = ["omk"]
Output: []

Example 3:
Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]

-- LeetCode: https://leetcode.com/problems/keyboard-row/description/

-- Solution:
To solve this problem, we can create a dictionary mapping each letter to its corresponding row on the keyboard. Then, for each word in the input array, we check if all its letters belong to the same row. If so, we add the word to the result list.

-- Complexity
Time complexity: O (M . K) -> Where M word array Length and K maximum length of word.
Space complexity: O(M).
*/

bool canTypeInOneRow(char *word)
{
    char *rows[] = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
    int rowIdx = -1;

    for (int i = 0; i < 3; i++)
    {
        if (strchr(rows[i], word[0]))
        {
            rowIdx = i;
            break;
        }
    }

    for (int i = 1; i < strlen(word); i++)
    {
        if (!strchr(rows[rowIdx], word[i]))
        {
            return false;
        }
    }

    return true;
}

char **findWords(char **words, int wordsSize, int *returnSize)
{
    char **result = (char **)malloc(wordsSize * sizeof(char *));
    *returnSize = 0;

    for (int i = 0; i < wordsSize; i++)
    {
        if (canTypeInOneRow(words[i]))
        {
            result[(*returnSize)++] = words[i];
        }
    }

    return result;
}

int main()
{
    char *words[] = {"Hello", "Alaska", "Dad", "Peace"};
    int wordsSize = sizeof(words) / sizeof(words[0]);
    int returnSize;
    char **result = findWords(words, wordsSize, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%s", result[i]);
        if (i < returnSize - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");

    free(result);
    return 0;
}
