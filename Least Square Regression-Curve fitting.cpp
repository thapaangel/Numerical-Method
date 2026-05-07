/*A) Fit a straight line to the following set of data points.
x=[1,2,3,4,5]
y=[3,4,5,6,8]
B) Plot the straight line thus obtained using graphing tool and add the plot to the report.
C) Use the plot generated in step B and find f(15).
D) Find the root of the straight line obtained in step A.
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int i, j, n;
    double Sxy = 0, Sx = 0, Sy = 0, Sx2 = 0, Sy2 = 0;
    double a, b;
    double x[10], y[10];

    printf("Enter the value of n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the values of x[%d] and y[%d]: ", i, i);
        scanf("%lf %lf", &x_val[i], &y_val[i]);
}

    printf("\n\ni \t\t  Sx \t\t  Sy \t\t Sxy \t\t Sx2 \t\t Sy2");
    for (i = 0; i < n; i++)
    {
        Sx += x[i];
        Sy += y[i];
        Sxy += x[i] * y[i];
        Sx2 += x[i] * x[i];
        Sy2 += y[i] * y[i];
        printf("\n\n%2d \t %10.5lf \t %10.5lf \t %10.5lf \t %10.5lf \t %10.5lf", i, Sx, Sy, Sxy, Sx2, Sy2);
    }

    b = (n * Sxy - Sx * Sy) / (n * Sx2 - Sx * Sx);
    a = (Sx2 * Sy - Sxy * Sx) / (n * Sx2 - Sx * Sx);
    printf("\n\n\na= %.5lf", a);
    printf("\nb= %.5lf", b);
    printf("\nThe regression line is y=%.5lf+%.5lfx", a, b);

    getch();
    return 0;
}

