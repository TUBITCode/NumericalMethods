// Write a Program to solve ODE by Using picard method
#include <stdio.h>
#include <math.h>

// Function to solve the ODE using Picard's method
void picardODE(double (*f)(double, double), double x0, double y0, double h, int n) {
    double x = x0, y = y0;
    for (int i = 0; i < n; i++) {
        double y_prev = y;
        y = y0 + h * f(x, y_prev);
        x += h;
        printf("At x = %lf, y = %lf\n", x, y);
    }
}

// Example function
double exampleFunction(double x, double y) {
    return x * y + 2 * y;
}

int main() {
    double x0, y0, h;
    int n;
    printf("Function f(x) = (x * y + 2 * y)\n");
    printf("Enter the initial x and y values: ");
    scanf("%lf %lf", &x0, &y0);
    printf("Enter the step size: ");
    scanf("%lf", &h);
    printf("Enter the number of steps: ");
    scanf("%d", &n);
    picardODE(exampleFunction, x0, y0, h, n);
    return 0;
}
