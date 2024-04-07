#include "stdio.h"
#include "stdint.h"

int main()
{
    float diff = 781000;
    uint32_t distanceDiff = 100;

    float res = distanceDiff / (diff / 1000000);
    res = 0;

    printf("res: %f\n", res);

    return 0;
}