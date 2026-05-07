#include <stdio.h>

// Function to perform Lagrange interpolation
float lagrangeInterpolation(float x[], float y[], int n, float xp) {
    float yp = 0;  // Interpolated y value
    for (int i = 0; i < n; i++) {
        float term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp += term;
    }
    return yp;
}

int main() {
    int n;
    printf("Enter the number of known data points: ");
    scanf("%d", &n);

    float x[n], y[n];
    printf("Enter the data points (x y pairs):\n");
    for (int i = 0; i < n; i++) 
	{
        scanf("%f %f", &x[i], &y[i]);
    }
    
    float xp;
    printf("Enter the x value for which you want to find the y value: ");
    scanf("%f", &xp);

    float yp = lagrangeInterpolation(x, y, n, xp);

    printf("The interpolated y value at x = %f is y = %f\n", xp, yp);

    return 0;
}

