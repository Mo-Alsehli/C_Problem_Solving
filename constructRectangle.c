/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <math.h> // for sqrt function

int sovleSqrtEqu(float *res, int a, int b, int c)
{
    double discriminant, root1, root2;
    // Check for division by zero (avoid if a is zero)
    if (a == 0)
    {
        printf("Error: a cannot be zero.\n");
        return 1;
    }

    // Calculate the discriminant
    discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        // Two real and distinct roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and distinct:\n");
        printf("x1 = %.2lf\n", root1);
        printf("x2 = %.2lf\n", root2);

        res[0] = root1;
        res[1] = root2;
        return 2;
    }
    else if (discriminant == 0)
    {
        // Two real and equal roots
        root1 = root2 = -b / (2 * a);
        printf("Roots are real and equal:\n");
        printf("x1 = x2 = %.2lf\n", root1);

        res[0] = root1;
        res[1] = root2;
        return 3;
    }
    else
    {
        // Two complex roots
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex:\n");
        printf("x1 = %.2lf + %.2lfi\n", realPart, imaginaryPart);
        printf("x2 = %.2lf - %.2lfi\n", realPart, imaginaryPart);
    }

    return 0;
}
int *constructRectangle(int area, int *returnSize)
{
    float res1[2] = {0.0};
    int res[2] = {0};
    int i = 0;
    // In this problem we will sove the equation: L^2 - (L-W)L - area = 0.
    // The general equation is in the form: aL^2 - bL - c = 0.

    int a = 1, b = 0, c = -area;

    do
    {
        sovleSqrtEqu(res1, a, b, c);
        b++;
        printf("res[0] = %.2f, res[1] = %.2f\n", res1[0], res1[1]);
    } while (!(((int)(res1[0]) == res1[0] && res1[0] > 0) || ((int)(res1[1]) == res1[1] && res1[1] > 0)));

    return res;
}