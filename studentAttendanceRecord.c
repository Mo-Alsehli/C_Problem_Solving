/*
-- Description:
You are given a string s representing an attendance record for a student where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:
'A': Absent.
'L': Late.
'P': Present.
The student is eligible for an attendance award if they meet both of the following criteria:
The student was absent ('A') for strictly fewer than 2 days total.
The student was never late ('L') for 3 or more consecutive days.
Return true if the student is eligible for an attendance award, or false otherwise.

-- Solution:
- We count Number of Absents and if it exceeds 2 we return false.
- We count Number of Consecutive Late and if it's equal to 3 or more we return false.
- If there are no more than 2 absents or No more than 2 consecutive Late we return True.

-- Time Complexity: O(n).
-- Space Complexity: O(1).
 */
#include <stdio.h>
#include "string.h"

int checkRecord(char *s)
{
    int i;
    int len = strlen(s);
    int absent = 0, consecutiveLate = 0;

    for (i = 0; i < len; i++)
    {
        if (s[i] == 'A')
        {
            absent++;
            if (absent >= 2)
                return 0;
        }

        if (s[i] == 'L')
        {
            consecutiveLate++;
            if (consecutiveLate >= 3)
            {
                return 0;
            }
        }
        else
        {
            consecutiveLate = 0;
        }
    }

    return 1;
}

int main()
{
    char s1[] = "PPALLP";
    printf("Input: %s\n", s1);
    printf("Eligible for award: %s\n", checkRecord(s1) ? "true" : "false"); // Output should be true

    char s2[] = "PPALLL";
    printf("Input: %s\n", s2);
    printf("Eligible for award: %s\n", checkRecord(s2) ? "true" : "false"); // Output should be false

    char s3[] = "PAALL";
    printf("Input: %s\n", s3);
    printf("Eligible for award: %s\n", checkRecord(s3) ? "true" : "false"); // Output should be false

    return 0;
}