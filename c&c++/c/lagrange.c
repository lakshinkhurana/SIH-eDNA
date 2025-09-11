#include <stdio.h>

double lagrangeInterpolation(double x, double *x_values, double *y_values, int n) {
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y_values[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (x - x_values[j]) / (x_values[i] - x_values[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    double x_values[] = {0, 1, 2, 3};
    double y_values[] = {1, 2, 0, 5};  // Example points: (0,1), (1,2), (2,0), (3,5)
    int n = sizeof(x_values) / sizeof(x_values[0]);

    double x = 1.5;  // Point to interpolate
    double interpolated_value = lagrangeInterpolation(x, x_values, y_values, n);

    printf("Interpolated value at x = %f: %f\n", x, interpolated_value);
    return 0;
}
