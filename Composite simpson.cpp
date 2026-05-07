#include <stdio.h>
#include <math.h>

// Function to calculate the value of the given function f(x) = sin(x)
float f(float x) {
    return sin(x);
}

// Function to apply the composite Simpson's rule
float simpson(float a, float b, int n) {
    if (n % 2 != 0) {
        printf("n must be an even number for Simpson's rule.\n");
        return 0.0;
    }
    
    float h = (b - a) / n;
    float sum = f(a) + f(b);

    printf("\t\tx\t\ty\n");
    for (int i = 1; i < n; i++) {
        float x = a + i * h;
        float y = f(x);
        printf("\t\t%.2f\t\t%.6f\n", x, y);
        
        if (i % 2 == 0) {
            sum += 2 * y;
        } else {
            sum += 4 * y;
        }
    }

    float result = (h / 3) * sum;
    return result;
}

int main() {
    float a = 0, b = 1.57;  // Integration limits (b = p/2 radians)
    int n;

    printf("The value of n is: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("n should be a positive integer.\n");
        return 1;
    }

    if (n % 2 != 0) {
        printf("n must be an even number for Simpson's rule.\n");
        return 1;
    }

    printf("\nIntegration = %f\n", simpson(a, b, n));
    return 0;
}

