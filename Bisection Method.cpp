#include <stdio.h>
#include <conio.h>
#include <math.h>
#define e 0.001
#define f(x) (3*x + sin(x) - exp(x))

int main() {
    float x1, x2, x3;
    float f1, f2, f3;
    float error;
    int i = 0;
    
    printf("Enter the initial values x1 and x2: ");
    scanf("%f %f", &x1, &x2);
    
    printf("Iteration\t x1\t\t x2\t\t f(x1)\t\t f(x2)\t\t x3\t\t f(x3)\t\t error\n");
    printf("---------------------------------------------------------------------------------\n");
    
    do {
        x3 = (x1 + x2) / 2; // Bisection Method Formula
        f1 = f(x1);
        f2 = f(x2);
        f3 = f(x3);
        error = fabs(x3 - x2);
        
        if (f1 * f3 < 0)
            x2 = x3;
        else
            x1 = x3;
        
        i++;
        
        printf("%d\t\t %f\t %f\t %f\t %f\t %f\t %f\t %f\n", i, x1, x2, f1, f2, x3, f3, error);
    } while (error > e);
    
    printf("Root: %f\n", x3);
    getch();
    return 0;
}


