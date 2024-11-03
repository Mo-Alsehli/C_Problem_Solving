#include <stdio.h>
#include <stdlib.h>

char **readBinaryWatch(int turnedOn, int *returnSize)
{
    char **result = (char **)malloc(190 * sizeof(char *)); // Maximum possible combinations
    *returnSize = 0;

    for (int hour = 0; hour < 12; hour++)
    {
        for (int minute = 0; minute < 60; minute++)
        {
            int totalOnBits = __builtin_popcount(hour) + __builtin_popcount(minute);

            if (totalOnBits == turnedOn)
            {
                // Format the time as "hour:minute" and add it to the result
                result[*returnSize] = (char *)malloc(8 * sizeof(char));
                snprintf(result[*returnSize], 8, "%d:%02d", hour, minute);
                (*returnSize)++;
            }
        }
    }

    return result;
}

int main()
{
    int turnedOn = 3;
    int returnSize;
    char **result = readBinaryWatch(turnedOn, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);

    return 0;
}
