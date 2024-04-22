/*
-- Description:
Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

In the American keyboard:
the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".

Example 1:
Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]

 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

char **findWords(char **words, int wordsSize, int *returnSize)
{
    char **rowChars = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    int i, maxSize = 0, j;
    qsort(rowChars[0], 10, sizeof(char), cmpfunc);
    qsort(rowChars[1], 9, sizeof(char), cmpfunc);

    for (i = 0; i < wordsSize; i++)
    {
        int wordSize = sizeof(words[i]) / sizeof(char);
        qsort(words[i], wordSize, sizeof(char), cmpfunc);
        maxSize = wordSize > maxSize ? wordSize : maxSize;
    }

    char **res = (char **)malloc(wordsSize * sizeof(char *));

    for (i = 0; i < wordsSize; i++)
    {
        res[i] = (char *)malloc(maxSize * sizeof(char));
    }

    for (i = 0; i < wordsSize; i++)
    {
        int size = sizeof(words[i]) / sizeof(char);
        for (j = 0; j < size; j++)
        {
            if (words[i][j] == rowChars[0])
            {
            }
        }
    }
}