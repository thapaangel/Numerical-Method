#include <stdio.h>
#include <math.h>

#define e 0.001 // Tolerance

// Define the function g(x) here
#define g(x) sqrt(1+x) // Example function: g(x) = cos(x)

int main() {
    float x0, x1;
    float error;
    int i = 0;

    printf("Enter the initial value x0: ");
    scanf("%f", &x0);

    printf("Iteration\t x0\t\t g(x0)\t\t x1\t\t error\n");
    printf("-----------------------------------------------------------------------------------------------\n");

    do {
        x1 = g(x0); // Fixed Point Iteration Formula
        error = fabs(x1 - x0);
        i++;

        printf("%d\t\t %f\t %f\t %f\t %f\n", i, x0, g(x0), x1, error);

        x0 = x1;
    } while (error > e);

    printf("Fixed Point: %f\n", x1);

    return 0;
}



