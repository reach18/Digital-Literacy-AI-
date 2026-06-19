#include <stdio.h>
#include <math.h>

/**
 * Solves the quadratic equation ax² + bx + c = 0
 * 
 * @param a  Coefficient of x²
 * @param b  Coefficient of x
 * @param c  Constant term
 * @param x1 Pointer to store the first root
 * @param x2 Pointer to store the second root
 * @return   2 if two real roots, 1 if one repeated root,
 *           0 if no real roots (complex), -1 if not quadratic (a=0)
 */
int solve_quadratic(double a, double b, double c, double *x1, double *x2) {
    if (a == 0.0) {
        return -1; // Not a quadratic equation
    }

    double discriminant = b * b - 4.0 * a * c;

    if (discriminant > 0.0) {
        // Two distinct real roots
        double sqrt_d = sqrt(discriminant);
        *x1 = (-b + sqrt_d) / (2.0 * a);
        *x2 = (-b - sqrt_d) / (2.0 * a);
        return 2;
    } else if (discriminant == 0.0) {
        // One repeated real root
        *x1 = *x2 = -b / (2.0 * a);
        return 1;
    } else {
        // No real roots (complex roots)
        *x1 = *x2 = 0.0; // Undefined for real output
        return 0;
    }
}

int main() {
    double a, b, c, x1, x2;

    printf("Quadratic Equation Solver: ax^2 + bx + c = 0\n");
    printf("Enter a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    int result = solve_quadratic(a, b, c, &x1, &x2);

    switch (result) {
        case -1:
            printf("Error: 'a' cannot be 0 (not a quadratic equation).\n");
            break;
        case 0:
            printf("No real roots (discriminant < 0).\n");
            // Optionally compute and display complex roots:
            printf("Complex roots: %.4f + %.4fi and %.4f - %.4fi\n",
                   -b / (2.0 * a), sqrt(-( b*b - 4.0*a*c)) / (2.0 * a),
                   -b / (2.0 * a), sqrt(-(b*b - 4.0*a*c)) / (2.0 * a));
            break;
        case 1:
            printf("One repeated root: x = %.4f\n", x1);
            break;
        case 2:
            printf("Two real roots: x1 = %.4f, x2 = %.4f\n", x1, x2);
            break;
    }

    return 0;
}