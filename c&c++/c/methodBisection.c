#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x - 4;  // Example function f(x) = x^2 - 4
}

double bisection(double (*f)(double), double a, double b, double tol, int max_iter) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval: f(a) and f(b) should have opposite signs.\n");
        return NAN;
    }
    
    double mid;
    for (int i = 0; i < max_iter; i++) {
        mid = (a + b) / 2.0;
        if (fabs(f(mid)) < tol || (b - a) / 2 < tol)
            return mid;
        
        if (f(mid) * f(a) < 0)
            b = mid;
        else
            a = mid;
    }
    return mid;
}

int main() {
    double root = bisection(f, 0, 3, 1e-6, 1000);
    printf("Root: %f\n", root);
    return 0;
}
