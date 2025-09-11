#include <stdio.h>

float f(float x, float y) {
    // Define the function dy/dx = f(x, y) here.
    return x + y; // Example: dy/dx = x + y
}

void rungeKutta(float x0, float y0, float x, float h) {
    int n = (int)((x - x0) / h); // Number of steps
    float k1, k2, k3, k4, y = y0;

    printf("x\t\ty\n");
    printf("%.4f\t%.4f\n", x0, y0);

    for (int i = 0; i < n; i++) {
        k1 = h * f(x0, y);
        k2 = h * f(x0 + h / 2, y + k1 / 2);
        k3 = h * f(x0 + h / 2, y + k2 / 2);
        k4 = h * f(x0 + h, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        
        // Update x
        x0 += h;

        printf("%.4f\t%.4f\n", x0, y);
    }
}

int main() {
    float x0, y0, x, h;

    printf("Enter initial values of x and y (x0 and y0): ");
    scanf("%f %f", &x0, &y0);
    printf("Enter the value of x at which y is required: ");
    scanf("%f", &x);
    printf("Enter step size h: ");
    scanf("%f", &h);

    rungeKutta(x0, y0, x, h);

    return 0;
}
