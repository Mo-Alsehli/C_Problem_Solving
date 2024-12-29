#include <stdio.h>
#include <stdlib.h>
#define F abc
#define B def
#define FB(arg) #arg
#define FB1(arg) FB(arg)
int main()
{
    int a = 1, b = 2, c = 3, d;
    d = (a = c, b += a, c = a + b + c);
    printf("%d %d %d %d\n", d, a, b, c);
}