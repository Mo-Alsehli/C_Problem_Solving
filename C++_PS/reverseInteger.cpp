/* 
-- auther: Mohamed Magdi
-- language: C++
**************************
-- Description:
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

Constraints:
-231 <= x <= 231 - 1

LeetCode: https://leetcode.com/problems/reverse-integer/description/
 */

#include <iostream>
#include <climits>

int reverse(int x) {
        int maxInt = INT_MAX;
        int minInt = INT_MIN;
        int res = 0;
        if(x > 0){
            while(x > 0){
                if(res > (maxInt / 10)){
                    return 0;
                }
                res *= 10;
                int rem = x % 10;
                res += rem;
                x /= 10;
            }
        }else if (x < 0){
           while(x < 0){
                if(res < (minInt / 10)){
                    return 0;
                }
                res *= 10;
                int rem = x % 10;
                res += rem;
                x /= 10;
            } 
        }

        return res;
    }


int main() {
    int x1 = 123;
    int x2 = -123;
    int x3 = 120;

    std::cout << "Input: " << x1 << " Output: " << reverse(x1) << std::endl;
    std::cout << "Input: " << x2 << " Output: " << reverse(x2) << std::endl;
    std::cout << "Input: " << x3 << " Output: " << reverse(x3) << std::endl;

    return 0;
}
