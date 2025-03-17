#include <stdio.h>
#include <stdlib.h>

void dividedDifference(double *x, double *y, double **dd, int n) {
    for (int i = 0; i < n; i++)
        dd[i][0] = y[i];

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            dd[i][j] = (dd[i + 1][j - 1] - dd[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}

int main() {
    double x[] = {0, 1, 2, 3};  // x values
    double y[] = {1, 2, 0, 5};  // y values
    int n = sizeof(x) / sizeof(x[0]);

    double **dd = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        dd[i] = (double *)malloc(n * sizeof(double));
    }

    dividedDifference(x, y, dd, n);

    printf("Divided Difference Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%lf ", dd[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(dd[i]);
    }
    free(dd);
    return 0;
}
