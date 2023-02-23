// Write a Program to solve PDE by Using Poission method
#include <stdio.h>
#include <math.h>

double f(double x, double y) {
    // Source term
    return sin(M_PI * x) * sin(M_PI * y);
}

void poisson(int n, double dx, double dy) {
    double u[n+1][n+1], unew[n+1][n+1];
    // Initialize the grid
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            u[i][j] = 0;
            unew[i][j] = 0;
        }
    }
    // Set boundary conditions
    for (int i = 0; i <= n; i++) {
        u[i][0] = sin(M_PI * i * dx);
        u[i][n] = sin(M_PI * i * dx);
        u[0][i] = sin(M_PI * i * dy);
        u[n][i] = sin(M_PI * i * dy);
    }

    // Iterate until convergence
    double error = 1;
    while (error > 1e-6) {
        error = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                unew[i][j] = (u[i-1][j] + u[i+1][j] + u[i][j-1] + u[i][j+1] + (dx*dx)*f(i*dx,j*dy)) / 4;
                error = fmax(error, fabs(unew[i][j] - u[i][j]));
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                u[i][j] = unew[i][j];
            }
        }
    }
    // Print the solution
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%lf ", u[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 10;
    double dx = 1.0 / n;
    double dy = 1.0 / n;
    poisson(n, dx, dy);
    return 0;
}
