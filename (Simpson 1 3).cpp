#include <stdio.h>

// Function to calculate f(x)
double f(double x) {
    return 1.0 / (1.0 + x * x);
}

// Function to implement Simpson's 1/3 rule
double simpson(double a, double b, int n) {
    if (n % 2 != 0) {
        printf("Number of intervals must be even.\n");
        return -1;
    }

    double h = (b - a) / n; // Step size
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
    double a = 0.0; // Lower limit
    double b = 1.0; // Upper limit
    int n = 1000; // Number of intervals (must be even)

    double result = simpson(a, b, n);
    if (result != -1) {
        printf("The approximate value of the integral using Simpson's 1/3 rule is: %f\n", result);
    }

    return 0;
}

