#include <stdio.h>

// Function to calculate f(x)
double f(double x) {
    return 1.0 / (1.0 + x * x);
}

// Function to implement the trapezoidal rule
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n; // Step size
    double sum = 0.5 * (f(a) + f(b)); // Starting with half the sum of the first and last terms

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return h * sum;
}

int main() {
    double a = 0.0; // Lower limit
    double b = 1.0; // Upper limit
    int n = 1000; // Number of intervals

    double result = trapezoidal(a, b, n);
    printf("The approximate value of the integral is: %f\n", result);

    return 0;
}

