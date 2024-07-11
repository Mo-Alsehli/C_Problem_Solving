#include <stdio.h>
void solve()
{
    int first = 10, second = 20;
    int third = first + second;
    {
        int third = second - first;
        printf("%d ", third);
    }
    printf("%d", third);
}
#include <stdio.h>
int main()
{
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr;

    *(ptr++) += 123;

    printf("%d %d", *ptr, *(ptr + 1));
}