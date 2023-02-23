// Write a Program to solve ODE by Using shooting method
#include <stdio.h>
#include <math.h>

double f(double x, double y, double yprime) {
    // function to be solved
    return yprime;
}

double g(double x, double y, double yprime) {
    // function to be solved
    return x*x + y*y;
}

void shooting(double x0, double y0, double yprime0, double x1, double y1, double h, double tol) {
    double x = x0, y = y0, yprime = yprime0;

    while (fabs(y - y1) > tol) {
        yprime0 += (y1 - y) / h;
        yprime = yprime0;
        for (double i = x0; i < x1; i += h) {
            double k1 = h * f(x, y, yprime);
            double l1 = h * g(x, y, yprime);
            double k2 = h * f(x + h/2, y + k1/2, yprime + l1/2);
            double l2 = h * g(x + h/2, y + k1/2, yprime + l1/2);
            double k3 = h * f(x + h/2, y + k2/2, yprime + l2/2);
            double l3 = h * g(x + h/2, y + k2/2, yprime + l2/2);
            double k4 = h * f(x + h, y + k3, yprime + l3);
            double l4 = h * g(x + h, y + k3, yprime + l3);
            y += (k1 + 2*k2 + 2*k3 + k4) / 6;
            yprime += (l1 + 2*l2 + 2*l3 + l4) / 6;
            x += h;
        }
    }
    printf("x = %lf, y = %lf, yprime = %lf\n", x1, y, yprime);
}

int main() {
    double x0 = 0, y0 = 1, yprime0 = 2, x1 = 1, y1 = 2, h = 0.1;
    double tol = 0.01;
    shooting(x0, y0, yprime0, x1, y1, h, tol);
    return 0;
}
