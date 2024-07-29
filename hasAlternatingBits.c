/*
-- Description:
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:
Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101

Example 2:
Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111.

Example 3:
Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.
 */

#include <stdio.h>
#include <stdbool.h>

bool hasAlternatingBits(int n)
{
    int onesFlag = 0, zerosFlag = 0;
    long int currBase = 1;

    for (int i = 0; i < 31; i++)
    {
        // Read number Bits
        int bitStatus = (n >> i) & 1;
        if (bitStatus == 1)
        {
            zerosFlag = 0;
            if (onesFlag == 1)
            {
                return false;
            }
            else
            {
                onesFlag = 1;
            }
        }
        else
        {
            onesFlag = 0;
            if (zerosFlag == 1)
            {
                return false;
            }
            else
            {
                zerosFlag = 1;
            }
        }
        // Break if the last bit in the number
        if (currBase > n)
        {
            break;
        }
        currBase *= 2;
    }

    return true;
}

int main()
{
    int n = 10; // Example number
    if (hasAlternatingBits(n))
    {
        printf("The number %d has alternating bits.\n", n);
    }
    else
    {
        printf("The number %d does not have alternating bits.\n", n);
    }
    return 0;
}
