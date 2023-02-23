// Write a Program to solve ODE by Using Rungee kutta  method
#include <stdio.h>
#include <math.h>

double f(double x, double y) {
    // function to be solved
    return x*x + y*y;
}

void rungeKutta(double x0, double y0, double h, int n) {
    double x = x0, y = y0;
    printf("x0 = %lf, y0 = %lf\n", x0, y0);
    for (int i = 1; i <= n; i++) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h/2, y + k1/2);
        double k3 = h * f(x + h/2, y + k2/2);
        double k4 = h * f(x + h, y + k3);
        double yn = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
        x = x + h;
        y = yn;
        printf("x%d = %lf, y%d = %lf\n", i, x, i, y);
    }
}

int main() {
    printf("f(x,y) : x*x + y*y\n");
    double x0 = 0, y0 = 1, h = 0.2;
    int n = 5;
    rungeKutta(x0, y0, h, n);
    return 0;
}
