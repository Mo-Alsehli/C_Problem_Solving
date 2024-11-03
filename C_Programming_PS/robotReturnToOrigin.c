/*
-- Description:
There is a robot starting at the position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.
You are given a string moves that represents the move sequence of the robot where moves[i] represents its ith move. Valid moves are 'R' (right), 'L' (left), 'U' (up), and 'D' (down).
Return true if the robot returns to the origin after it finishes all of its moves, or false otherwise.

Example 1:
Input: moves = "UD"
Output: true
Explanation: The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started. Therefore, we return true.

Example 2:
Input: moves = "LL"
Output: false
Explanation: The robot moves left twice. It ends up two "moves" to the left of the origin. We return false because it is not at the origin at the end of its moves.

LeetCode: https://leetcode.com/problems/robot-return-to-origin/description/

-- Solution:
# Approach
- If each `up` is encountered with one `down` and each `left` is encountered with one `right` that means the robot returned to origin.

# Complexity
- Time complexity: O(n)

- Space complexity: O(1)
*/

#include <stdio.h>

int judgeCircle(char *moves)
{
    int upDownCount = 0, leftRightCount = 0;
    int i;
    for (i = 0; moves[i] != '\0'; i++)
    {
        if (moves[i] == 'L')
            leftRightCount++;
        else if (moves[i] == 'R')
            leftRightCount--;
        else if (moves[i] == 'U')
            upDownCount++;
        else if (moves[i] == 'D')
            upDownCount--;
    }

    if (upDownCount == 0 && leftRightCount == 0)
        return 1;

    return 0;
}

int main()
{
    char moves[] = "UDLR";
    if (judgeCircle(moves))
    {
        printf("The robot returns to the origin.\n");
    }
    else
    {
        printf("The robot does not return to the origin.\n");
    }
    return 0;
}