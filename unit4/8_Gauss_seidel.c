// Write a Program to implement Gauss Seidal Method
#include <stdio.h>
#include <math.h>

#define MAX_ITER 100
#define TOLERANCE 0.0001

void gaussSeidal(double a[][10], double x[], double b[], int n)
{
    double error, s;
    int count = 0;

    do
    {
        error = 0;
        for (int i = 0; i < n; i++)
        {
            s = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    s += a[i][j] * x[j];
            }
            double prev = x[i];
            x[i] = (b[i] - s) / a[i][i];
            error += fabs(prev - x[i]);
        }
        count++;
    } while (error > TOLERANCE && count < MAX_ITER);
}

int main()
{
    double a[10][10], x[10], b[10];
    int n;

    printf("Enter the size of matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of matrix A: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &a[i][j]);

    printf("Enter the elements of matrix B: ");
    for (int i = 0; i < n; i++)
        scanf("%lf", &b[i]);

    printf("Enter the initial values of X: ");
    for (int i = 0; i < n; i++)
        scanf("%lf", &x[i]);

    gaussSeidal(a, x, b, n);

    printf("The solution is: \n");
    for (int i = 0; i < n; i++)
        printf("X[%d] = %lf\n", i, x[i]);

    return 0;
}
