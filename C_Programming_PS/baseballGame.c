/*
-- Description:
You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.
You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:
An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.

Example 1:

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.

 */
#include <stdio.h>
#include <stdlib.h>

int calPoints(char **operations, int operationsSize)
{
    int sum = 0, currScore = 0, prevScore = 0, prevPrevScore = 0, i;
    int arr[1000] = {0}, j = 0;

    for (i = 0; i < operationsSize; i++)
    {
        prevScore = j > 0 ? arr[j - 1] : 0;
        prevPrevScore = j > 1 ? arr[j - 2] : 0;
        switch (operations[i][0])
        {
        case '+':
            currScore = prevScore + prevPrevScore;
            arr[j] = currScore;
            j++;
            break;
        case 'D':
            currScore = (prevScore * 2);
            arr[j] = currScore;
            j++;
            break;
        case 'C':
            j--;
            break;
        default:
            currScore = atoi(operations[i]);
            arr[j] = currScore;
            j++;
        }
    }

    for (i = 0; i < j; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    char *ops1[] = {"5", "2", "C", "D", "+"};
    int opsSize1 = 5;
    printf("Output: %d\n", calPoints(ops1, opsSize1)); // Output: 30

    char *ops2[] = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    int opsSize2 = 8;
    printf("Output: %d\n", calPoints(ops2, opsSize2)); // Output: 27

    char *ops3[] = {"1", "C"};
    int opsSize3 = 2;
    printf("Output: %d\n", calPoints(ops3, opsSize3)); // Output: 0

    return 0;
}