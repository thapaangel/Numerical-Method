#include <stdio.h>

// Function to integrate
double f(double x) {
    return 1.0 / (1.0 + x * x);
}

// Composite Simpson's 3/8 rule function
double simpsons38Rule(double a, double b, int n) {
    if (n % 3 != 0) {
        printf("Number of intervals must be a multiple of 3.\n");
        return -1;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 3 * f(x);
        }
    }

    return (3.0 * h / 8.0) * sum;
}

int main() {
    double a = 0.0;
    double b = 10.0;
    int n = 12;  // Number of intervals (must be a multiple of 3)

    double result = simpsons38Rule(a, b, n);
    if (result != -1) {
        printf("The integral of 1/(1+x^2) from %f to %f is approximately: %f\n", a, b, result);
    }

    return 0;
}

