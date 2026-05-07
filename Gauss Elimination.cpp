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

void gaussElimination(float matrix[N][N + 1], float solution[N]) {
    // Forward elimination
    for (int i = 0; i < N; i++) {
        // Search for maximum in this column
        float maxEl = abs(matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < N; k++) {
            if (abs(matrix[k][i]) > maxEl) {
                maxEl = abs(matrix[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k = i; k <= N; k++) {
            float tmp = matrix[maxRow][k];
            matrix[maxRow][k] = matrix[i][k];
            matrix[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k = i + 1; k < N; k++) {
            float c = -matrix[k][i] / matrix[i][i];
            for (int j = i; j <= N; j++) {
                if (i == j) {
                    matrix[k][j] = 0;
                } else {
                    matrix[k][j] += c * matrix[i][j];
                }
            }
        }
    }

    // Back substitution
    for (int i = N - 1; i >= 0; i--) {
        solution[i] = matrix[i][N] / matrix[i][i];
        for (int k = i - 1; k >= 0; k--) {
            matrix[k][N] -= matrix[k][i] * solution[i];
        }
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

    gaussElimination(matrix, solution);

    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %0.2f\n", i + 1, solution[i]);
    }

    return 0;
}

