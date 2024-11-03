/*
-- Description:
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.

LeetCode: https://leetcode.com/problems/number-complement/description/

-- Solution:
- get the number of bits required to represent num.
- compute the mask that is represented by 1's to the number of bits.
- make an XOR operation between the mask and the number so that every set bit in num is converted into zero in result and vice versa.

-- Complexity
Time complexity: O(logn)
Space complexity: O(1)
 */

int findComplement(int num)
{
    int n = num;
    char bitPos = 0;

    while (n)
    {
        bitPos++;
        n >>= 1;
    }

    unsigned int mask = (1u << bitPos) - 1;

    return num ^ mask;
}

/*
int findComplement(int num) {
    int res = num;
    char lastOnePos = 0;
    for(int i = 0; i < 31; i++){
        if(((num >> i) & 1) == 1){
            lastOnePos = i;
        }
    }

    for(int i = 0; i <= lastOnePos; i++){
        if(((num >> i) & 1) == 1){
            res &= ~(1 << i);
        }else{
            res |= (1 << i);
        }
    }

    return res;
}
*/

#include <stdio.h>

int main()
{
    int num1 = 5;
    printf("Complement of %d: %d\n", num1, findComplement(num1));

    int num2 = 1;
    printf("Complement of %d: %d\n", num2, findComplement(num2));

    return 0;
}
