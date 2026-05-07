#include <stdio.h>

// Function to integrate
double f(double x) {
    return 1.0 / (1.0 + x * x);
}

// Composite Simpson's 1/3 rule function
double simpsonsRule(double a, double b, int n) {
    if (n % 2 != 0) {
        printf("Number of intervals must be even.\n");
        return -1;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 4 * f(x);
        }
    }

    return (h / 3) * sum;
}

int main() {
    double a = 0.0;
    double b = 10.0;
    int n = 10;  // Number of intervals (must be even)

    double result = simpsonsRule(a, b, n);
    if (result != -1) {
        printf("The integral of 1/(1+x^2) from %f to %f is approximately: %f\n", a, b, result);
    }

    return 0;
}

