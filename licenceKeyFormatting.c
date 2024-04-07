#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *licenseKeyFormatting(char *s, int k)
{
    // Calculate the length of the formatted string
    int len = strlen(s);
    int count = 0; // Count of characters excluding dashes
    for (int i = 0; i < len; i++)
    {
        if (s[i] != '-')
            count++;
    }

    // Calculate the length of the first group
    int firstGroupLen = count % k;
    if (firstGroupLen == 0)
        firstGroupLen = k;

    // Allocate memory for the formatted string
    char *formatted = (char *)malloc((count + count / k + 1) * sizeof(char));
    int idx = 0;

    // Add characters to the formatted string
    for (int i = 0; i < len; i++)
    {
        if (s[i] != '-')
        {
            // Convert lowercase letters to uppercase
            formatted[idx++] = (s[i] >= 'a' && s[i] <= 'z') ? s[i] - 32 : s[i];

            // Insert dash if necessary
            if (idx == firstGroupLen || ((idx)-firstGroupLen) % k == 0)
            {
                printf("idx: %d, firstGroupLen: %d \n", idx, firstGroupLen);
                formatted[idx++] = '-';
            }
        }
    }

    // Remove the trailing dash if present
    if (formatted[idx - 1] == '-')
        formatted[idx - 1] = '\0';
    else
        formatted[idx] = '\0';

    return formatted;
}

int main()
{
    char s1[] = "5F3Z-2e-9-w";
    int k1 = 4;
    char *formatted1 = licenseKeyFormatting(s1, k1);
    printf("Formatted License Key 1: %s\n", formatted1);
    free(formatted1);

    char s2[] = "2-5g-3-J";
    int k2 = 2;
    char *formatted2 = licenseKeyFormatting(s2, k2);
    printf("Formatted License Key 2: %s\n", formatted2);
    free(formatted2);

    return 0;
}
