#include <stdio.h>
#include <stdbool.h>

bool isUgly(int n)
{
    if (n <= 0)
    {
        return false;
    }

    while (n % 2 == 0)
    {
        n /= 2;
    }

    while (n % 3 == 0)
    {
        n /= 3;
    }

    while (n % 5 == 0)
    {
        n /= 5;
    }

    return n == 1;
}

int main()
{
    int n1 = 6;
    int n2 = 1;
    int n3 = 14;

    printf("isUgly(%d): %s\n", n1, isUgly(n1) ? "true" : "false");
    printf("isUgly(%d): %s\n", n2, isUgly(n2) ? "true" : "false");
    printf("isUgly(%d): %s\n", n3, isUgly(n3) ? "true" : "false");

    return 0;
}
