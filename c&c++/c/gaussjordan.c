#include <stdio.h>

#define SIZE 10  // Maximum size of the matrix

void displayMatrix(float matrix[SIZE][SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%0.3f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void gaussJordan(float matrix[SIZE][SIZE], int n) {
    float augmented[SIZE][2 * SIZE];
    
    // Initializing augmented matrix with original matrix and identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmented[i][j] = matrix[i][j];
            augmented[i][j + n] = (i == j) ? 1 : 0; // Identity matrix part
        }
    }

    // Applying Gauss-Jordan elimination
    for (int i = 0; i < n; i++) {
        // Check if the diagonal element is zero and swap with a non-zero row if needed
        if (augmented[i][i] == 0) {
            int swapRow = i + 1;
            while (swapRow < n && augmented[swapRow][i] == 0) swapRow++;
            if (swapRow == n) {
                printf("Matrix is singular and cannot be inverted.\n");
                return;
            }
            for (int j = 0; j < 2 * n; j++) {
                float temp = augmented[i][j];
                augmented[i][j] = augmented[swapRow][j];
                augmented[swapRow][j] = temp;
            }
        }

        // Make the diagonal element 1
        float diagElement = augmented[i][i];
        for (int j = 0; j < 2 * n; j++) {
            augmented[i][j] /= diagElement;
        }

        // Make all elements in the current column (except for the diagonal) 0
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = augmented[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    augmented[k][j] -= factor * augmented[i][j];
                }
            }
        }
    }

    // Display the inverse matrix (the right half of the augmented matrix)
    printf("The inverse matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            printf("%0.3f\t", augmented[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    float matrix[SIZE][SIZE];

    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("Original matrix:\n");
    displayMatrix(matrix, n);

    gaussJordan(matrix, n);

    return 0;
}
