/*
Hamming Weight Problem.
Description:
Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
Case:
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

Solution:
In this code, we define the hammingWeight function that takes a 32-bit unsigned integer n as input and returns the number of '1' bits (Hamming weight). We initialize the count variable to 0. Then, in a loop, we check each bit of n by performing bitwise AND operation (&) with 1. If the result is non-zero, it means the rightmost bit is 1, so we increment the count. After checking the bit, we shift n to the right by 1 bit using the right shift operator (>>). The loop continues until n becomes zero, meaning we have checked all the bits of the integer. Finally, we return the count.
*/

#include <stdint.h>
#include <stdio.h>

int hammingWeight(uint32_t n)
{
    int count = 0;

    while (n != 0)
    {
        if (n & 1)
        {
            count++;
        }
        n = n >> 1;
    }

    return count;
}

int main()
{
    uint32_t n = 0b11111111111111111111111111111101;
    int weight = hammingWeight(n);

    printf("Hamming Weight: %d\n", weight);

    return 0;
}
