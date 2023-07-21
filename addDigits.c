/*
Description:
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

Link: https://leetcode.com/problems/add-digits/description/

Example 1:
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
Since 2 has only one digit, return it.

*/

#include <stdio.h>

int addDigits(int num)
{
    while (num >= 10)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

/*
int addDigits(int num){
    if(num < 10){
        return num;
    }else if(num == 10){
        return 1;
    }
    int res = num, temp = num;
    while(res >= 10){
        res = 0;
        while(temp > 0){
                int rem = temp % 10;
                res += rem;
                temp = temp / 10;
            }
            temp = res;
    }
    return res;
}
*/

int main()
{
    int num = 38;
    int result = addDigits(num);
    printf("Result: %d\n", result);
    return 0;
}
