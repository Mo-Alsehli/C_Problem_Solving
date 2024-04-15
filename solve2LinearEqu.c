// Substitution Method:

#include <stdio.h>

int main()
{
    // Declare variables
    double a1, a2, b1, b2, c1, c2, x, y;

    // Input coefficients
    printf("Enter coefficients for the first equation (Ax + By = C):\n");
    printf("A: ");
    scanf("%lf", &a1);
    printf("B: ");
    scanf("%lf", &b1);
    printf("C: ");
    scanf("%lf", &c1);

    printf("Enter coefficients for the second equation (Dx + Ey = F):\n");
    printf("D: ");
    scanf("%lf", &a2);
    printf("E: ");
    scanf("%lf", &b2);
    printf("F: ");
    scanf("%lf", &c2);

    // Check if coefficients allow solving (avoid division by zero)
    if (a1 * b2 == a2 * b1)
    {
        printf("Equations are dependent or parallel. No unique solution.\n");
        return 1;
    }

    // Solve for x in terms of y (assuming a1 != 0)
    x = (c1 - b1 * y) / a1;

    // Substitute x into the second equation to solve for y
    y = (c2 - a2 * x) / b2;

    // Substitute y back into the first equation to solve for x (optional)
    // x = (c1 - b1 * y) / a1;  // This line can be uncommented

    // Print the solutions
    printf("Solution:\n");
    printf("x = %.2lf\n", x);
    printf("y = %.2lf\n", y);

    return 0;
}
