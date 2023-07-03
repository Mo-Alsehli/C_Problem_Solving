#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
-- Description:
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
*/

char *convertToTitle(int columnNumber)
{
    // Allocate memory for the resulting column title
    char *columnTitle = (char *)malloc(sizeof(char) * 8); // Assuming columnNumber <= 2^31 - 1

    int index = 0;

    while (columnNumber > 0)
    {
        int remainder = (columnNumber - 1) % 26;
        printf("%d\n", remainder);
        columnTitle[index++] = 'A' + remainder;
        columnNumber = (columnNumber - 1) / 26;
    }

    // Reverse the column title
    int left = 0;
    int right = index - 1;

    while (left < right)
    {
        char temp = columnTitle[left];
        columnTitle[left++] = columnTitle[right];
        columnTitle[right--] = temp;
    }

    // Null-terminate the column title
    columnTitle[index] = '\0';

    return columnTitle;
}

int main()
{
    int columnNumber = 28;

    char *columnTitle = convertToTitle(columnNumber);

    printf("Column Title: %s\n", columnTitle);

    free(columnTitle);

    return 0;
}
