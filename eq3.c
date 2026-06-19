#include <stdio.h>
#include <math.h>

/*
 * Solves the quadratic equation ax² + bx + c = 0
 *
 * Returns:
 *  2 -> Two real roots
 *  1 -> One repeated root
 *  0 -> No real roots
 * -1 -> Not a quadratic equation (a = 0)
 */
int solve_quadratic(double a, double b, double c, double *x1, double *x2)
{
    if (a == 0.0)
    {
        return -1;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        double sqrt_d = sqrt(discriminant);

        *x1 = (-b + sqrt_d) / (2 * a);
        *x2 = (-b - sqrt_d) / (2 * a);

        return 2;
    }
    else if (discriminant == 0)
    {
        *x1 = *x2 = -b / (2 * a);
        return 1;
    }
    else
    {
        *x1 = *x2 = 0;
        return 0;
    }
}

int main()
{
    double a, b, c, x1, x2;

    printf("Quadratic Equation Solver\n");
    printf("Equation: ax^2 + bx + c = 0\n");
    printf("Enter a, b, and c: ");

    /* Input validation */
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        printf("Error: Please enter numbers only.\n");
        return 1;
    }

    int result = solve_quadratic(a, b, c, &x1, &x2);

    switch (result)
    {
        case -1:
            printf("Error: a cannot be 0.\n");
            break;

        case 0:
        {
            double realPart = -b / (2 * a);
            double imagPart = sqrt(-(b * b - 4 * a * c)) / (2 * a);

            printf("No real roots.\n");
            printf("Complex roots:\n");
            printf("x1 = %.4f + %.4fi\n", realPart, imagPart);
            printf("x2 = %.4f - %.4fi\n", realPart, imagPart);
            break;
        }

        case 1:
            printf("One repeated root:\n");
            printf("x = %.4f\n", x1);
            break;

        case 2:
            printf("Two real roots:\n");
            printf("x1 = %.4f\n", x1);
            printf("x2 = %.4f\n", x2);
            break;
    }

    return 0;
}