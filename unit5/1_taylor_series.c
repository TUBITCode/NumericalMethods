// Write a Program to solve ODE by Using Taylors series method
#include <stdio.h>
#include <math.h>

// Function to evaluate the derivative of a function at a point
double derivative(double (*f)(double), double x, int n) {
    double h = 0.0001;
    if (n == 0)
        return f(x);
    else if (n == 1)
        return (f(x + h) - f(x)) / h;
    else
        return (derivative(f, x + h, n - 1) - derivative(f, x, n - 1)) / h;
}

// Function to solve the ODE using Taylor series method
void taylorODE(double (*f)(double), double x0, double y0, double h, int n) {
    double x = x0, y = y0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            y += h * derivative(f, x, j) / (j + 1);
        }
        x += h;
        printf("At x = %lf, y = %lf\n", x, y);
    }
}

// Example function
double exampleFunction(double x) {
    return x * x + 2 * x;
}

int main() {
    double x0, y0, h;
    int n;
    printf("Function f(x) = (x * x + 2 * x)\n");
    printf("Enter the initial x and y values: ");
    scanf("%lf %lf", &x0, &y0);
    printf("Enter the step size: ");
    scanf("%lf", &h);
    printf("Enter the number of steps: ");
    scanf("%d", &n);
    taylorODE(exampleFunction, x0, y0, h, n);
    return 0;
}
