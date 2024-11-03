/*
-- Description:
International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:
'a' maps to ".-", 'b' maps to "-...", 'c' maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:
[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.
For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". We will call such a concatenation the transformation of a word.
Return the number of different transformations among all words we have.

Example 1:
Input: words = ["gin","zen","gig","msg"]
Output: 2
Explanation: The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."
There are 2 different transformations: "--...-." and "--...--.".

Example 2:
Input: words = ["a"]
Output: 1

leetCode: https://leetcode.com/problems/unique-morse-code-words/description/

-- Solution:
# Approach
- Create an array containing all characters morse code.
- Create an array for all possible transformations of the words in the current array.
- loop through words and generate each morse code.
- store unique codes and negelet repeated ones.
# Complexity
- Time complexity: O(N*M)
- Space complexity: O(N)
*/

#include <stdio.h>
#include <string.h>

int isUnique(char transformation[][100], int size, char *str)
{
    if (size == 0)
    {
        return 1;
    }
    for (int i = 0; i < size; i++)
    {
        if (strcmp(transformation[i], str) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int uniqueMorseRepresentations(char words[][100], int wordsSize)
{

    if (wordsSize == 1)
        return 1;
    char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    char transformations[100][100];
    char code[60];
    int uniqueCounter = 0;

    for (int i = 0; i < wordsSize; i++)
    {
        for (int j = 0; j < strlen(words[i]); j++)
        {
            strcat(code, morse[words[i][j] - 'a']);
        }
        if (isUnique(transformations, uniqueCounter, code))
        {
            strcpy(transformations[uniqueCounter], code);
            uniqueCounter++;
        }
        strcpy(code, "");
    }

    return uniqueCounter;
}

int main()
{
    // Example 1
    char words1[][100] = {"gin", "zen", "gig", "msg"};
    int wordsSize1 = 4;
    printf("Output: %d\n", uniqueMorseRepresentations(words1, wordsSize1)); // Output: 2

    // Example 2
    char words2[][100] = {"a"};
    int wordsSize2 = 1;
    printf("Output: %d\n", uniqueMorseRepresentations(words2, wordsSize2)); // Output: 1

    return 0;
}
