#include <stdio.h>

double f(double x) {
    return x * x;  // Example function f(x) = x^2
}

double trapezoidalRule(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;  // Width of each subinterval
    double sum = 0.5 * (f(a) + f(b));  // Initial and final terms

    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);  // Sum of the middle terms
    }

    return sum * h;  // Multiply by the width of the subintervals
}

int main() {
    double a = 0;  // Lower limit
    double b = 2;  // Upper limit
    int n = 100;   // Number of subintervals

    double result = trapezoidalRule(f, a, b, n);
    printf("Approximate integral from %f to %f: %f\n", a, b, result);

    return 0;
}
