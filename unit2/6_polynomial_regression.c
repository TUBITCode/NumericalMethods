//	WAP to implement least square approximation using polynomial least square method.
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the divided difference table
void dividedDiffTable(double x[], double y[], int n, double **dd) {
    int i, j;
    for (i = 0; i < n; i++)
        dd[i][0] = y[i];
    for (j = 1; j < n; j++)
        for (i = j; i < n; i++)
            dd[i][j] = (dd[i][j-1] - dd[i-1][j-1]) / (x[i] - x[i-j]);
}

// Function to evaluate the value of the polynomial at a given point
double evaluate(double x[], double **dd, int n, double value) {
    double ans = dd[0][0];
    for (int i = 1; i < n; i++) {
        double term = dd[i][i];
        for (int j = 0; j < i; j++)
            term *= (value - x[j]);
        ans += term;
    }
    return ans;
}

int main() {
    int n;
    double *x, *y, **dd, value;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    x = (double*) malloc(n * sizeof(double));
    y = (double*) malloc(n * sizeof(double));
    dd = (double**) malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
        dd[i] = (double*) malloc(n * sizeof(double));
    printf("Enter the data points: \n");
    for (int i = 0; i < n; i++)
        scanf("%lf %lf", &x[i], &y[i]);
    dividedDiffTable(x, y, n, dd);
    printf("Enter the value at which the polynomial is to be evaluated: ");
    scanf("%lf", &value);
    printf("Answer: %lf\n", evaluate(x, dd, n, value));
    return 0;
}
