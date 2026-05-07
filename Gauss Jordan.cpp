#include <stdio.h>
#include <stdlib.h>

#define N 3 // Number of variables

void printMatrix(float matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%0.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussJordanElimination(float matrix[N][N + 1], float solution[N]) {
    for (int i = 0; i < N; i++) {
        // Make the diagonal contain all 1's
        float diagElement = matrix[i][i];
        for (int j = 0; j <= N; j++) {
            matrix[i][j] /= diagElement;
        }

        // Make the other elements in column zero
        for (int k = 0; k < N; k++) {
            if (k != i) {
                float c = matrix[k][i];
                for (int j = 0; j <= N; j++) {
                    matrix[k][j] -= c * matrix[i][j];
                }
            }
        }
    }

    // Extract the solutions
    for (int i = 0; i < N; i++) {
        solution[i] = matrix[i][N];
    }
}

int main() {
    float matrix[N][N + 1] = {
        {0.143, 0.357, 2.01, -5.173},
        {-1.31, -0.911, 1.99, -5.458},
        {11.2, -4.3, -0.605, 4.415}
    };

    float solution[N];

    printf("Original augmented matrix:\n");
    printMatrix(matrix);

    gaussJordanElimination(matrix, solution);

    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %0.2f\n", i + 1, solution[i]);
    }

    return 0;
}

