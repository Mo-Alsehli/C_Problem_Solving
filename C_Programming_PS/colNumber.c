#include <stdio.h>
#include <string.h>

int titleToNumber(char *columnTitle)
{
    int columnNumber = 0;
    int n = strlen(columnTitle);

    for (int i = 0; i < n; i++)
    {
        int digitValue = columnTitle[i] - 'A' + 1;
        columnNumber = columnNumber * 26 + digitValue;
    }

    return columnNumber;
}

int main()
{
    char columnTitle[] = "ZY";
    int columnNumber = titleToNumber(columnTitle);

    printf("Column Number: %d\n", columnNumber);

    return 0;
}
