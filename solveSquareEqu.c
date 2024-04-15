#include <stdio.h>
#include <math.h> // for sqrt function

int *sovleSqrtEqu(int a, int b, int c)
{
    int discriminant, root1, root2;
    int res[2] = {0};
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
        return res;
    }
    else if (discriminant == 0)
    {
        // Two real and equal roots
        root1 = root2 = -b / (2 * a);
        printf("Roots are real and equal:\n");
        printf("x1 = x2 = %.2lf\n", root1);

        res[0] = root1;
        res[1] = root2;
        return res;
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

int main()
{
    // Declare variables
    double a, b, c, discriminant, root1, root2;

    // Input coefficients
    printf("Enter coefficients for the quadratic equation (ax^2 + bx + c = 0):\n");
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);

    // Check for division by zero (avoid if a is zero)
    if (a == 0)
    {
        printf("Error: a cannot be zero.\n");
        return 1;
    }

    // Calculate the discriminant
    discriminant = b * b - 4 * a * c;

    // Print solution(s) based on discriminant
    if (discriminant > 0)
    {
        // Two real and distinct roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and distinct:\n");
        printf("x1 = %.2lf\n", root1);
        printf("x2 = %.2lf\n", root2);
    }
    else if (discriminant == 0)
    {
        // Two real and equal roots
        root1 = root2 = -b / (2 * a);
        printf("Roots are real and equal:\n");
        printf("x1 = x2 = %.2lf\n", root1);
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
