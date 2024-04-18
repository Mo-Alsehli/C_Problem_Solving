/*
-- Auther: Mohamed Magdi
-- Date: 4/18/2024

-- Description
Our hero Teemo is attacking an enemy Ashe with poison attacks! When Teemo attacks Ashe, Ashe gets poisoned for a exactly duration seconds. More formally, an attack at second t will mean Ashe is poisoned during the inclusive time interval [t, t + duration - 1]. If Teemo attacks again before the poison effect ends, the timer for it is reset, and the poison effect will end duration seconds after the new attack.
You are given a non-decreasing integer array timeSeries, where timeSeries[i] denotes that Teemo attacks Ashe at second timeSeries[i], and an integer duration.
Return the total number of seconds that Ashe is poisoned.

Example 1:
Input: timeSeries = [1,4], duration = 2
Output: 4
Explanation: Teemo's attacks on Ashe go as follows:
- At second 1, Teemo attacks, and Ashe is poisoned for seconds 1 and 2.
- At second 4, Teemo attacks, and Ashe is poisoned for seconds 4 and 5.
Ashe is poisoned for seconds 1, 2, 4, and 5, which is 4 seconds in total.

-- Solution:
To solve this problem, we need to iterate through the timeSeries array and calculate the duration of poisoning for each attack. If the time difference between consecutive attacks is less than the duration, we consider only the time difference. Otherwise, we consider the full duration for that attack.

-- Time Complexity: O(n)
-- Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int findPoisonedDuration(int *timeSeries, int timeSeriesSize, int duration)
{
    if (timeSeriesSize == 0)
        return 0;

    int totalDuration = duration;
    for (int i = 1; i < timeSeriesSize; i++)
    {
        int timeDiff = timeSeries[i] - timeSeries[i - 1];
        totalDuration += timeDiff < duration ? timeDiff : duration;
    }
    return totalDuration;
}

int main()
{
    int timeSeries[] = {1, 4};
    int duration = 2;
    int timeSeriesSize = sizeof(timeSeries) / sizeof(timeSeries[0]);

    int result = findPoisonedDuration(timeSeries, timeSeriesSize, duration);
    printf("Output: %d\n", result);

    return 0;
}
