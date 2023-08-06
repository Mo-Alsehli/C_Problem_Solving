#include <stdio.h>
#include <stdbool.h>

/*
Description:
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.



Example 1:

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.

Solution:

To find the first bad version efficiently while minimizing the number of API calls, we can use a binary search algorithm. This approach utilizes the fact that if a version is bad, all subsequent versions will also be bad.


*/

bool isBadVersion(int version)
{
    // This function is provided by the problem statement
    // and should be implemented externally.
    // It returns true if the given version is bad, and false otherwise.
    // For this example, let's assume all versions starting from `bad` are bad.
    return version >= 4;
}

int firstBadVersion(int n)
{
    // Simple binary search implementation.
    int left = 1;
    int right = n;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

int main()
{
    int n = 10;
    int bad = 4;

    int result = firstBadVersion(n);

    printf("First bad version: %d\n", result);

    return 0;
}
