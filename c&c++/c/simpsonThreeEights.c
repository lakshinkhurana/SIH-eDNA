#include <stdio.h>

double f(double x) {
    return x * x;  // Example function f(x) = x^2
}

double simpsonsThreeEighthRule(double (*f)(double), double a, double b, int n) {
    if (n % 3 != 0) {
        printf("Error: Number of subintervals must be a multiple of 3.\n");
        return 0;
    }

    double h = (b - a) / n;  // Width of each subinterval
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += (i % 3 == 0 ? 2 : 3) * f(x);
    }

    return (3 * h / 8) * sum;
}

int main() {
    double a = 0;  // Lower limit
    double b = 2;  // Upper limit
    int n = 99;    // Number of subintervals (must be a multiple of 3)

    double result = simpsonsThreeEighthRule(f, a, b, n);
    printf("Approximate integral from %f to %f: %f\n", a, b, result);

    return 0;
}
