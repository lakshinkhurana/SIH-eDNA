#include <stdio.h>
#include <math.h>

#define SIZE 10  // Maximum size of the matrix
#define EPSILON 0.0001  // Convergence threshold
#define MAX_ITER 1000   // Maximum number of iterations

void getMatrix(float matrix[SIZE][SIZE], int n) {
    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }
}

void displayVector(float vector[SIZE], int n) {
    for (int i = 0; i < n; i++) {
        printf("%0.4f\n", vector[i]);
    }
}

float powerMethod(float matrix[SIZE][SIZE], float eigenvector[SIZE], int n) {
    float tempVector[SIZE], eigenvalue = 0, prevEigenvalue;
    int iteration = 0;

    // Initialize eigenvector to (1, 1, ..., 1)
    for (int i = 0; i < n; i++) {
        eigenvector[i] = 1;
    }

    do {
        // Multiply matrix with the eigenvector
        for (int i = 0; i < n; i++) {
            tempVector[i] = 0;
            for (int j = 0; j < n; j++) {
                tempVector[i] += matrix[i][j] * eigenvector[j];
            }
        }

        // Find the maximum value in tempVector for normalization (approximate eigenvalue)
        prevEigenvalue = eigenvalue;
        eigenvalue = fabs(tempVector[0]);
        for (int i = 1; i < n; i++) {
            if (fabs(tempVector[i]) > eigenvalue) {
                eigenvalue = fabs(tempVector[i]);
            }
        }

        // Normalize tempVector to get the next eigenvector approximation
        for (int i = 0; i < n; i++) {
            eigenvector[i] = tempVector[i] / eigenvalue;
        }

        iteration++;
        
    } while (fabs(eigenvalue - prevEigenvalue) > EPSILON && iteration < MAX_ITER);

    return eigenvalue;
}

int main() {
    int n;
    float matrix[SIZE][SIZE], eigenvector[SIZE], eigenvalue;

    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    getMatrix(matrix, n);

    eigenvalue = powerMethod(matrix, eigenvector, n);

    printf("\nDominant Eigenvalue: %0.4f\n", eigenvalue);
    printf("Corresponding Eigenvector:\n");
    displayVector(eigenvector, n);

    return 0;
}
