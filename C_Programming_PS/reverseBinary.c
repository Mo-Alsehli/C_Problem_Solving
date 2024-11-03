#include <stdio.h>
#include <stdint.h>

/*
-- Problem Definition:
- Reverse bits of a given 32 bits unsigned integer.
- Example 1:
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.



*/

uint32_t reverseBits(uint32_t n)
{
    uint32_t result = 0;

    for (int i = 0; i < 32; i++)
    {
        result = (result << 1) | (n & 1);
        n = n >> 1;
    }

    return result;
}
// TEST CASE:
// 001101011101
// 000000000001
// 000000000000
// 000000000001

// 000110101110
// 000000000001
// 000000000010
// 000000000010

// 000011010111
// 000000000001
// 000000000100
// 000000000101

int main()
{
    uint32_t n = 43261596;
    uint32_t reversed = reverseBits(n);

    // printf("Reversed Bits: %u\n", reversed);
    printf("%d\n", 3 | 1);

    return 0;
}
