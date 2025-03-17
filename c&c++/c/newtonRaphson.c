#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x - 4;  // Example function f(x) = x^2 - 4
}

double df(double x) {
    return 2 * x;      // Derivative f'(x) = 2x
}

double newtonRaphson(double (*f)(double), double (*df)(double), double x0, double tol, int max_iter) {
    double x = x0;
    for (int i = 0; i < max_iter; i++) {
        double x_new = x - f(x) / df(x);
        if (fabs(x_new - x) < tol)
            return x_new;
        x = x_new;
    }
    return x;
}

int main() {
    double root = newtonRaphson(f, df, 1.0, 1e-6, 1000);
    printf("Root: %f\n", root);
    return 0;
}
